#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::condition_variable cv;
std::mutex mt;
int _amount{0};

void addMoney(int amount)
{
    std::lock_guard<std::mutex> lg(mt);
    _amount += amount;
    cv.notify_one();
}

void withDrawMoney(int amount)
{
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, []()
            { return _amount != 0; });
    if (_amount < amount)
        throw std::runtime_error("Cannot withdraw balance insufficient!");
    _amount -= amount;
}

int main()
{
    try
    {
        std::thread t1(&addMoney, 1);
        std::thread t2(&withDrawMoney, 10);
        std::cout << "Amount :- " << _amount << '\n';
        t1.join();
        t2.join();
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << '\n';
    }
}
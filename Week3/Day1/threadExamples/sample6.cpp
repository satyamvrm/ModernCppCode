/*
    RAII:
*/

/*  one object of this class is responsibe for one connection mechanism to the bank */

#include <iostream>
#include <thread>
#include <mutex>
#include <array>

class BankingOperation
{
private:
    /* data */
    int _amount{0};
    std::mutex mt;
    static BankingOperation *_soloHeroObj;
    BankingOperation(int amount) : _amount{amount} {}

public:
    BankingOperation() = delete;
    BankingOperation(const BankingOperation &) = delete;
    BankingOperation(const BankingOperation &&) = delete;
    BankingOperation &operator=(const BankingOperation &) = delete;
    BankingOperation &operator=(const BankingOperation &&) = delete;
    ~BankingOperation() = default;

    void withdraw()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::lock_guard<std::mutex> lk(mt);
            _amount -= 10;
        }
    }

    void deposit()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::lock_guard<std::mutex> lk(mt);
            _amount += 1;
        }
    }

    static BankingOperation *getFirstInstence(int amount)
    {
        // if pointer is not null, object is already exist
        if (_soloHeroObj)
        {
            // return address of existing object
            return _soloHeroObj;
        }
        else
        {
            // no object is pre existing create one
            _soloHeroObj = new BankingOperation(amount);
            return _soloHeroObj;
        }
    }

    int amount() const { return _amount; }
};

BankingOperation *BankingOperation::_soloHeroObj{nullptr};

int main()
{
    BankingOperation *obj = BankingOperation::getFirstInstence(1000);
    std::array<std::thread, 2> arr = {
        std::thread(&BankingOperation::withdraw, obj),
        std::thread(&BankingOperation::deposit, obj)};
    std::cout << obj->amount() << '\n';
    for (std::thread &t : arr)
    {
        std::cout << "In join :- " <<obj->amount() << '\n';
        if (t.joinable())
            t.join();
    }
    std::cout << obj->amount() << '\n';
}
#include "DataHandler.h"
#include <thread>
#include <future>

int main()
{
    std::unique_ptr<DataHandler> ptr;
    ptr = DataHandler::getInstance();
    std::thread t1(&DataHandler::displayData, ptr);
    t1.join();
    std::cout << '\n';
    std::future<void> as = std::async(&DataHandler::displayData, ptr);
    as.get();
    std::cout << '\n';
    std::future<void> as2 = std::async(display, ptr);
    as2.get();
    std::cout << '\n';
}
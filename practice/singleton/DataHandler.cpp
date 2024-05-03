#include "DataHandler.h"
#include <mutex>

std::mutex mt;

std::unique_ptr<DataHandler> DataHandler::getInstance()
{
    // if(!_soloObject){
    //     _soloObject.reset(new DataHandler());
    // }
    // return std::move(_soloObject);
    if(!_soloObject) _soloObject = new DataHandler();
    return std::move(_soloObject);
}

void DataHandler::displayData()
{
    std::lock_guard<std::mutex> lg(mt);
    for (int i : _data)
    {
        std::cout << i << " ";
    }
}

void display(std::shared_ptr<DataHandler> ptr)
{
    ptr->displayData();
}

#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <iostream>
#include <vector>
#include <memory>

class DataHandler
{
private:
    std::vector<int> _data{1, 2, 3, 4, 5};
    static std::unique_ptr<DataHandler> _soloObject;
    DataHandler() = default;

public:
    DataHandler(const DataHandler &) = default;
    DataHandler(DataHandler &&) = default;
    DataHandler &operator=(const DataHandler &) = default;
    DataHandler &operator=(DataHandler &&) = default;
    ~DataHandler() {}

    static std::unique_ptr<DataHandler> getInstance();
    void displayData();
};
void display(std::shared_ptr<DataHandler> ptr);

#endif // DATAHANDLER_H

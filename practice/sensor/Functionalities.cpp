#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.push_back(
        std::make_shared<Sensor>(
            1,
            "ABC",
            SensorTypes::CABIN_PRESSURE,
            102
        )
    );
    data.push_back(
        std::make_shared<Sensor>(
            2,
            "PQR",
            SensorTypes::TEMPERATURE,
            98
        )
    );
    data.push_back(
        std::make_shared<Sensor>(
            3,
            "XYZ",
            SensorTypes::TYPE_PRESSURE,
            671
        )
    );
}

void showReadings(Container &data)
{
    if(data.empty()) throw EmptyData("Data is Empty");
    for(std::shared_ptr<Sensor> c : data){
        std::cout<<*c;
    }
}

int showCount(Container &data)
{
    if(data.empty()) throw EmptyData("Data is Empty");
    int count{0};
    for(std::shared_ptr<Sensor> c : data){
        count++;
    }
    return count;
}

int NumberOfType(Container &data, SensorTypes type)
{
    if(data.empty()) throw EmptyData("Data is Empty");
    int count{0};
    for(std::shared_ptr<Sensor> c : data){
        if(c->type()==type)  count++;
    }
    return count;
}

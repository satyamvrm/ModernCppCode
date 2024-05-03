#include "Functionalities.h"

#include "customException.h"
void CreateObject(Container &data)
{
    std::shared_ptr<Car> d1 = std::make_shared<Car>("Dezire",800000.0f,"XFS",std::make_shared<Engine>(800,330),CarType::SEDAN);
    data.push_back(d1);
    std::shared_ptr<Car> d2 = std::make_shared<Car>("Altroz",890000.0f,"GJD",std::make_shared<Engine>(880,360),CarType::HATCHBACK);
    data.push_back(d2);
    std::shared_ptr<Car> d3 = std::make_shared<Car>("Safari",1800000.0f,"SUMO",std::make_shared<Engine>(900,430),CarType::SUV);
    data.push_back(d3);
}


void DisplayObjects(Container &data)
{
    for(std::shared_ptr<Car> c : data){
        std::cout<<*c;
    }
}

int TotalHorsePower(Container &data)
{
    if(data.empty()) throw customException("Data is Empty");
    int tHP{0};
    for(std::shared_ptr<Car> c : data){
        tHP+=c->engine()->horsepower();
    }
    return tHP;
}

#include "Funcationalities.h"
#include "ElectricCar.h"
#include "DieselCar.h"

void CreateObject(std::vector<Car *> &data)
{
    data.push_back(new ElectricCar("nexonEV", 80, 150, 1870000, 33, 2, 300, 320, 600));
    data.push_back(new ElectricCar("XUV400", 70, 140, 1270000, 33, 2, 300, 320, 600));
    data.push_back(new ElectricCar("Safari", 90, 180, 1700000, 35, 3, 300, 300, 600));
    data.push_back(new DieselCar("nexon D", 80, 150, 1870000,30,20));
    data.push_back(new DieselCar("XUV400 D", 70, 140, 1270000, 30,22));
    data.push_back(new DieselCar("Safari D", 90, 180, 1700000, 30,24));
}

void DeleteObject(std::vector<Car *> &data)
{
    // Old style
    //     for(int i=0;i<data.size();i++){
    //         delete data[i];
    //     }

    // Morden CPP
    for (Car *p : data)
    {
        delete p;
    }
}

void DisplayObjects(std::vector<Car *> &data){
    for(Car* c : data){
        if(typeid(*c)==typeid(DieselCar)){
            DieselCar* ob = dynamic_cast<DieselCar*>(c);
            std::cout<<*ob<<'\n';
        }
        if(typeid(*c)==typeid(ElectricCar)){
            ElectricCar* ob = dynamic_cast<ElectricCar*>(c);
            std::cout<<*ob<<'\n';
        }
    }
}

#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include<queue>
#include<vector>
#include<variant>
#include"Bike.hpp"



using CarPointer = std::shared_ptr<Car>;
using BikePointer = std::shared_ptr<Bike>;
using VehicleVariant = std::variant<CarPointer, BikePointer>;
using VehicleVriantVector = std::vector<VehicleVariant>;
// using VehiclePriorityQueue = std::priority_queue<VehicleVariant>;
using EnginePointer = std::shared_ptr<Engine>;
using EngineContainer = std::vector<EnginePointer>;

struct LessComparator {
    bool operator()(const VehicleVariant& obj1, const VehicleVariant& obj2) {
        if(std::holds_alternative<CarPointer>(obj1) && std::holds_alternative<CarPointer>(obj2)){
            CarPointer c1 = std::get<CarPointer>(obj1);
            CarPointer c2 = std::get<CarPointer>(obj2);
            return c1.get()->carPrice() > c2.get()->carPrice();
        }
        else if(std::holds_alternative<CarPointer>(obj1) && std::holds_alternative<BikePointer>(obj2)){
            CarPointer c1 = std::get<CarPointer>(obj1);
            BikePointer c2 = std::get<BikePointer>(obj2);
            return c1.get()->carPrice() > c2.get()->bikePrice();
        }
        else if(std::holds_alternative<BikePointer>(obj1) && std::holds_alternative<CarPointer>(obj2)){
            BikePointer c1 = std::get<BikePointer>(obj1);
            CarPointer c2 = std::get<CarPointer>(obj2);
            return c1.get()->bikePrice() > c2.get()->carPrice();
        }
        else{
            BikePointer c1 = std::get<BikePointer>(obj1);
            BikePointer c2 = std::get<BikePointer>(obj2);
            return c1.get()->bikePrice() > c2.get()->bikePrice();
        }
    }
};


using VehiclePriorityQueue =  std::priority_queue<VehicleVariant, VehicleVriantVector, LessComparator>;


void CreateObjects(EngineContainer& engineData, VehiclePriorityQueue& vehiclePQ);



#endif // FUNCTIONALITIES_HPP

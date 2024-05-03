#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <queue>
#include <variant>
#include <vector>
#include "Car.hpp"
#include "Bike.hpp"

using CarPointer = std::shared_ptr<Car>;
using BikePointer = std::shared_ptr<Bike>;
using EngineContainer = std::vector<std::shared_ptr<Engine>>;

using EngineContainerRef = std::reference_wrapper<EngineContainer>;
using VehiclePriorityQueue = std::priority_queue<std::variant<CarPointer, BikePointer>>;

struct LessComparator
{
    bool operator()(const std::variant<CarPointer, BikePointer> &obj1, const std::variant<CarPointer, BikePointer> &obj2)
    {
        if (std::holds_alternative<CarPointer>(obj1) && std::holds_alternative<CarPointer>(obj2))
        {
            CarPointer c1 = std::get<CarPointer>(obj1);
            CarPointer c2 = std::get<CarPointer>(obj2);
            return c1.get()->carPrice() > c2.get()->carPrice();
        }
        else if (std::holds_alternative<CarPointer>(obj1) && std::holds_alternative<BikePointer>(obj2))
        {
            CarPointer c1 = std::get<CarPointer>(obj1);
            BikePointer c2 = std::get<BikePointer>(obj2);
            return c1.get()->carPrice() > c2.get()->bikePrice();
        }
        else if (std::holds_alternative<BikePointer>(obj1) && std::holds_alternative<CarPointer>(obj2))
        {
            BikePointer c1 = std::get<BikePointer>(obj1);
            CarPointer c2 = std::get<CarPointer>(obj2);
            return c1.get()->bikePrice() > c2.get()->carPrice();
        }
        else
        {
            BikePointer b1 = std::get<BikePointer>(obj1);
            BikePointer b2 = std::get<BikePointer>(obj2);
            return b1.get()->bikePrice() > b2.get()->bikePrice();
        }
    }
};

using VehiclePriorityQueueMin = std::priority_queue<std::variant<CarPointer, BikePointer>, std::vector<std::variant<CarPointer, BikePointer>>, LessComparator>;

using VehiclePriorityQueueRef = std::reference_wrapper<VehiclePriorityQueue>;

// void CreateObjects(EngineContainerRef engineData, VehiclePriorityQueueRef vehicleData);
void CreateObjects(EngineContainerRef engineData, VehiclePriorityQueueMin &vehicleData);
void CreateObjectsMin(EngineContainerRef engineData, std::vector<std::variant<CarPointer, BikePointer>> &vehicleVariantVector);

#endif // FUNCTIONALITIES_HPP

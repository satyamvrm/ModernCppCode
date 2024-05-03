#include "Functionalities.hpp"

void CreateObjects(EngineContainer& engineData, VehiclePriorityQueue &vehiclePQ)
{

    engineData.emplace_back(
        std::make_shared<Engine>("E001", 200, EngineType::ICE)
    );
    engineData.emplace_back(
        std::make_shared<Engine>("E002", 300, EngineType::EV)
    );

    vehiclePQ.push(
        std::make_shared<Car>("C001", "Honda", CarType::HATCHBACK, 1000000.0f, std::ref(engineData[0]))
    );
    vehiclePQ.push(
        std::make_shared<Car>("C002", "BMW", CarType::SEDAN, 2000000.0f, std::ref(engineData[1]))
    );
    vehiclePQ.push(
        std::make_shared<Bike>("B001", "Honda", BikeType::LUXURY, 3000000.0f, std::ref(engineData[0]))
    );
    vehiclePQ.push(
        std::make_shared<Bike>("B002", "BMW", BikeType::CLASSIC, 4000000.0f, std::ref(engineData[1]))
    );

}
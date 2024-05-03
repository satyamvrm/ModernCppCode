#include "Functionalities.hpp"

void CreateObjects(EngineContainerRef engineData, VehiclePriorityQueueMin& vehicleData)
{

    engineData.get().emplace_back(
        std::make_shared<Engine>("E001", 100, EngineType::ICE)
    );
    engineData.get().emplace_back(
        std::make_shared<Engine>("E002", 200, EngineType::EV)
    );

    vehicleData.push(
        std::make_shared<Car>("C001", "Honda", CarType::HATCHBACK, 100000.0f, engineData.get()[0])
    );
    vehicleData.push(
        std::make_shared<Bike>("B001", "Honda", BikeType::CLASSIC, 200000.0f, engineData.get()[1])
    );
    vehicleData.push(
        std::make_shared<Car>("C002", "BMW", CarType::SEDAN, 500000.0f, engineData.get()[0])
    );
    vehicleData.push(
        std::make_shared<Bike>("B002", "BMW", BikeType::LUXURY, 600000.0f, engineData.get()[1])
    );
}

void CreateObjectsMin(EngineContainerRef engineData, std::vector<std::variant<CarPointer, BikePointer>>& vehicleVariantVector)
{
    vehicleVariantVector.emplace_back(
        std::make_shared<Car>("C001", "Honda", CarType::HATCHBACK, 100000.0f, engineData.get()[0])
    );
    vehicleVariantVector.emplace_back(
        std::make_shared<Bike>("B001", "Honda", BikeType::CLASSIC, 200000.0f, engineData.get()[1])
    );
    vehicleVariantVector.emplace_back(
        std::make_shared<Car>("C002", "BMW", CarType::SEDAN, 500000.0f, engineData.get()[0])
    );
    vehicleVariantVector.emplace_back(
        std::make_shared<Bike>("B002", "BMW", BikeType::LUXURY, 600000.0f, engineData.get()[1])
    );
}

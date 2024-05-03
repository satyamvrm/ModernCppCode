#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "Car.h"
#include <functional>
#include <algorithm>
#include <numeric>
#include <vector>

using CarPtr = std::shared_ptr<Car>;
using EngineContainer = std::vector<Engine>;
using CarContainer = std::vector<CarPtr>;

class Operations
{
private:
    /* data */
    EngineContainer engins;
    CarContainer cars;
    static std::unique_ptr<Operations> _soloObject;
    Operations() = default;

public:
    Operations(Operations &) = delete;
    Operations(Operations &&) = delete;
    Operations &operator=(Operations &) = delete;
    Operations &operator=(Operations &&) = delete;
    ~Operations() = default;

    static std::unique_ptr<Operations>& getInstance();

    void createObject();
    void display();

    std::vector<std::reference_wrapper<Engine>> ReturnEngineReferance();

    bool allAbove();

    int avgHorsepower(float price);

    EngineType findEngineType(std::string reg);

    std::reference_wrapper<Engine> highestTorque();

};

#endif // OPERATIONS_H

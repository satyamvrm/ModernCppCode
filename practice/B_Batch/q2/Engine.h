#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "EngineType.h"

class Engine
{
private:
    /* data */
    std::string _engine_name;
    int _engine_torque;
    int _horsepower;
    EngineType _engineType;

public:
    Engine() = default;
    Engine(const Engine &) = default;
    Engine(Engine &&) = default;
    Engine &operator=(const Engine &) = delete;
    Engine &operator=(Engine &&) = delete;
    ~Engine() = default;

    Engine(
        std::string engine_name,
        int engine_torque,
        int horsepower,
        EngineType engineType);

    std::string engineName() const { return _engine_name; }

    int engineTorque() const { return _engine_torque; }

    int horsepower() const { return _horsepower; }

    EngineType engineType() const { return _engineType; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

std::string displayEnum(EngineType t);

#endif // ENGINE_H

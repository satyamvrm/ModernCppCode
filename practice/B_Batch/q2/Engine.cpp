#include "Engine.h"
std::ostream &operator<<(std::ostream &os, const Engine &rhs)
{
    os << "_engine_name: " << rhs._engine_name
       << " _engine_torque: " << rhs._engine_torque
       << " _horsepower: " << rhs._horsepower
       << " _engineType: " << displayEnum(rhs._engineType);
    return os;
}

std::string displayEnum(EngineType t)
{
    if (t == EngineType::CRDI)
        return "CRDI";
    else if (t == EngineType::TURBOCHARED)
        return "TURBOCHARED";
    else
        return "MPFI";
}

Engine::Engine(std::string engine_name, int engine_torque, int horsepower, EngineType engineType)
    : _engine_name{engine_name}, _engine_torque{engine_torque}, _horsepower{horsepower}, _engineType{engineType}
{
}
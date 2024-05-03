#include "Engine.hpp"


std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "_engineId: " << rhs._engineId
       << " _engineHorsepower: " << rhs._engineHorsepower
       << " _engineType: " << static_cast<int>(rhs._engineType);
    return os;
}


Engine::Engine(std::string engineId, int engineHorsepower, EngineType engineType)
    : _engineId(engineId), _engineHorsepower(engineHorsepower), _engineType(engineType) {}

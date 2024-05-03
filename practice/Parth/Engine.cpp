#include "Engine.h"
std::ostream &operator<<(std::ostream &os, const Engine &rhs)
{
    os << "_engineId: " << rhs._engineId
       << " _hp: " << rhs._hp
       << " _type: " << (rhs._type == EngineType::EV ? "EV" : "ICE");
    return os;
}

Engine::Engine(std::string engineId, int hp, EngineType t)
    : _engineId{engineId},
      _hp{hp},
      _type{t}
{
}
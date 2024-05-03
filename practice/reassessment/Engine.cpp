#include "Engine.h"

std::string displayEnum(EngineType t){
    if(t==EngineType::DIESEL) return "Diesel";
    else return "Petrol";
}

std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "_Etype: " << displayEnum(rhs._Etype)
       << " _hp: " << rhs._hp
       << " _cc: " << rhs._cc;
    return os;
}

Engine::Engine(EngineType etype, int hp, int cc) : _Etype{etype}, _hp{hp}, _cc{cc}
{
}
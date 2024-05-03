#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "EngineType.h"

class Engine
{
private:
    /* data */
    std::string _engineId;
    int _hp;
    EngineType _type;

public:
    Engine() = delete;
    Engine(Engine &) = delete;
    Engine(Engine &&) = delete;
    Engine &operator=(Engine &) = delete;
    Engine &operator=(Engine &&) = delete;
    ~Engine() =default;

    Engine(std::string engineId, int hp, EngineType t);

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};


#endif // ENGINE_H

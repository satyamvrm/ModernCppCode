#ifndef ENGINE_HPP
#define ENGINE_HPP

#include<string>
#include <ostream>
#include"EngineType.hpp"

class Engine
{
private:
    std::string _engineId;
    int _engineHorsepower;
    EngineType _engineType;

public:
    Engine() = delete;
    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator=(const Engine&) = delete;
    Engine& operator=(Engine&&) = delete;
    ~Engine() = default;

    Engine(std::string engineId, int engineHorsepower, EngineType engineType);

    std::string engineId() const { return _engineId; }
    int engineHorsepower() const { return _engineHorsepower; }
    EngineType engineType() const { return _engineType; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);

    
    
};

#endif // ENGINE_HPP

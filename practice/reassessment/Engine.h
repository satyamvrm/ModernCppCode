#ifndef ENGINE_H
#define ENGINE_H
#include "EngineType.h"
#include <ostream>
#include <memory>

class Engine
{
private:
    EngineType _Etype;
    int _hp;
    int _cc;

public:
    Engine() = default;
    Engine(const Engine &) = delete;             // disabled copy constructor
    Engine(Engine &&) = delete;                  // disabled move constructor (modern cpp)
    Engine &operator=(const Engine &) = delete;  //= operator is disabled to avoid copying,deleted copy assignment operator
    Engine &operator=(const Engine &&) = delete; // to avoid copy pasting,deleted move assignment operator(modern cpp)
    ~Engine() = default;                         // destructor enabled

    Engine(EngineType etype, int hp, int cc);

    EngineType etype() const { return _Etype; }
    void setEtype(const EngineType &Etype) { _Etype = Etype; }

    int hp() const { return _hp; }
    void setHp(int hp) { _hp = hp; }

    int cc() const { return _cc; }
    void setCc(int cc) { _cc = cc; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};
std::string displayEnum(EngineType t);

#endif // ENGINE_H

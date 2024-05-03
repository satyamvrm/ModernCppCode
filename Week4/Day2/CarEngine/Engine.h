#ifndef ENGINE_H
#define ENGINE_H
#include <ostream>

class Engine
{
private:
    /* data */
    int _horsePower;
    float _torque;
    

public:
    Engine(/* args */) = delete;
    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator=(const Engine&)=delete;
    Engine&& operator=(const Engine&&)=delete;
    ~Engine() {}

    Engine(int horsePower, float torque);

    int horsePower() const { return _horsePower; }
    void setHorsePower(int horsePower) { _horsePower = horsePower; }

    float torque() const { return _torque; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);

    
};

#endif // ENGINE_H

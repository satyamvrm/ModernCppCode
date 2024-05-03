#ifndef ENGINE_H
#define ENGINE_H
#include <ostream>

class Engine
{
private:
    int m_horsepower;
    int m_torque;
public:
    //default constructor deleted
    Engine()=delete;
    //default copy constructor deleted
    Engine(const Engine&) = delete;
    // default move constructor deleted 
    Engine(const Engine&&) = delete;
    // default assignment operator deleted 
    Engine &operator=(const Engine&) = delete; 
    // default move operator deleted
    Engine &operator=(const Engine&&) = delete; 
    // default distructor enabled 
    ~Engine()=default;

    //parameterized constructor
    Engine(int horsepower, int torque);

    int horsepower() const { return m_horsepower; }
    void setHorsepower(int horsepower) { m_horsepower = horsepower; }

    int torque() const { return m_torque; }
    void setTorque(int torque) { m_torque = torque; }

    // output stream operator overloaded
    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);

    
};

#endif // ENGINE_H

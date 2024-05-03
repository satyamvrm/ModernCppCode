#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H


#include "AutomobileType.h"
#include<iostream>

class Automobile
{
private:
    // data members for the automobile class
    std::string _model_name{""};
    AutomobileType _automobile_type{AutomobileType::PRIVATE};
    float _automobile_price{0.0f};
    float _automobile_mileage{0.0f};   

public:
    //default constructor enabled
    Automobile()=default;
    //default copy constructor disabled
    Automobile(const Automobile&) = delete;
    // default move constructor disabled 
    Automobile(const Automobile&&) = delete;
    // default assignment operator disabled 
    Automobile &operator=(const Automobile&) = delete; 
    // default move operator disabled
    Automobile &operator=(const Automobile&&) = delete; 
    // default distructor enabled 
    ~Automobile()=default;

    // parameterized constructor
    Automobile(std::string name, AutomobileType type, float value, float milage);


    //getter and setters
    std::string modelName() const { return _model_name; }
    void setModelName(const std::string &model_name) { _model_name = model_name; }

    AutomobileType automobileType() const { return _automobile_type; }
    void setAutomobileType(const AutomobileType &automobile_type) { _automobile_type = automobile_type; }

    float automobilePrice() const { return _automobile_price; }
    void setAutomobilePrice(float automobile_price) { _automobile_price = automobile_price; }

    float automobileMileage() const { return _automobile_mileage; }
    void setAutomobileMileage(float automobile_mileage) { _automobile_mileage = automobile_mileage; }

    //outstream operator overloding
    friend std::ostream &operator<<(std::ostream &os, const Automobile &rhs);
    
};

#endif // AUTOMOBILE_H

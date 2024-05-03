#ifndef CAR_H
#define CAR_H
#include<string>
#include <iostream>
#include"carType.h"
#include<future>
#include "Engine.h"

// using EnginePointer = std::shared_ptr<Engine>;
// using EngineRef = std::reference_wrapper<EnginePointer>;


class Car
{
private:
    static Car* _solo_object;
    std::string _model;
    int _year_of_manufacturing;
    CarType _Ctype;
    // EngineRef _engine;
    
    Car(std::string model ,int year_of_manufacturing, CarType ctype):
    _model{model}, _year_of_manufacturing{year_of_manufacturing}, _Ctype{ctype}{}

public:
    Car() = delete;
    Car(const Car & ) = delete;    // disabled copy constructor 
    Car(Car &&) = delete; // disabled move constructor (modern cpp)
    Car &operator=(const Car &) = delete;  //= operator is disabled to avoid copying,deleted copy assignment operator
    Car &operator=(const Car &&) = delete; // to avoid copy pasting,deleted move assignment operator(modern cpp)
    ~Car() = default;    // destructor enabled

    static Car* getFirstInstance(std::string model ,std::future<int> &ft, CarType ctype){
        if(_solo_object){
            return _solo_object;
        }
        else{
            int n = ft.get();
            _solo_object = new Car(model, n, ctype);
            return _solo_object;
        }
    }


    std::string model() const { return _model; }
    void setModel(const std::string &model) { _model = model; }

    int yearOfManufacturing() const { return _year_of_manufacturing; }
    void setYearOfManufacturing(int year_of_manufacturing) { _year_of_manufacturing = year_of_manufacturing; }

    CarType ctype() const { return _Ctype; }
    void setCtype(const CarType &Ctype) { _Ctype = Ctype; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
    
};
std::string displayEnum(CarType t);

#endif // CAR_H



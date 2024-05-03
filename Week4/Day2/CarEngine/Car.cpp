#include "Car.h"

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_id: " << rhs._id
       << " _price: " << rhs._price
       << " _model: " << rhs._model
       << " _engine: " << *rhs._engine;
    return os;
}

Car::Car(std::string id, std::string model, std::shared_ptr<Engine> engine, CarType ctype)
    : _id{id}, _model{model}, _engine{engine}, _type{ctype}{}

//constructor delication use multiple constroctor togeather to make the object
//we cannot use delegated constructor and member list initialization
Car::Car(std::string id, float price, std::string model, std::shared_ptr<Engine> engine, CarType ctype)
    : Car(id,model,engine,ctype)
{
    _price = price;
}


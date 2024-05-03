#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Car.h"
#include "Bike.h"
#include <variant>
#include <queue>
#include <mutex>
#include <functional>
#include <vector>
#include "Exception.h"
#include <map>

using CarPtr = std::shared_ptr<Car>;
using BikePtr = std::shared_ptr<Bike>;
using ObjectType = std::variant<CarPtr, BikePtr>;

struct LessComparitor
{
    bool operator()(const ObjectType &obj1, const ObjectType &obj2)
    {
        if (std::holds_alternative<CarPtr>(obj1) && std::holds_alternative<CarPtr>(obj2))
        {
            CarPtr c1 = std::get<CarPtr>(obj1);
            CarPtr c2 = std::get<CarPtr>(obj2);
            return c1.get()->getPrice() > c2.get()->getPrice();
        }
        else if (std::holds_alternative<CarPtr>(obj1) && std::holds_alternative<BikePtr>(obj2))
        {
            CarPtr c1 = std::get<CarPtr>(obj1);
            BikePtr c2 = std::get<BikePtr>(obj2);
            return c1.get()->getPrice() > c2.get()->getPrice();
        }
        else if (std::holds_alternative<BikePtr>(obj1) && std::holds_alternative<CarPtr>(obj2))
        {
            BikePtr c1 = std::get<BikePtr>(obj1);
            CarPtr c2 = std::get<CarPtr>(obj2);
            return c1.get()->getPrice() > c2.get()->getPrice();
        }
        else
        {
            BikePtr b1 = std::get<BikePtr>(obj1);
            BikePtr b2 = std::get<BikePtr>(obj2);
            return b1.get()->getPrice() > b2.get()->getPrice();
        }
    }
};

struct GreaterComparitor
{
    bool operator()(const ObjectType &obj1, const ObjectType &obj2)
    {
        float t1, t2;
        std::visit([&](auto &&o)
                   { t1 = o->getPrice(); },
                   obj1);
        std::visit([&](auto &&o)
                   { t2 = o->getPrice(); },
                   obj2);
        return t1 < t2;
    }
};

// using Container = std::priority_queue<ObjectType, std::vector<ObjectType>, LessComparitor>;
using Container1 = std::priority_queue<ObjectType, std::vector<ObjectType>, LessComparitor>;
using Container2 = std::priority_queue<ObjectType, std::vector<ObjectType>, GreaterComparitor>;
using EngineVector = std::vector<std::shared_ptr<Engine>>;

void createObject(Container1 &data, EngineVector &e);
void displayObject(Container1 data);
void createObject(Container2 &data, EngineVector &e);
void displayObject(Container2 data);

std::map<std::string, CarPtr> allCarsWithIds(Container1 data);
std::map<std::string, BikePtr> allBikesWithIds(Container1 data);

Container2 mapToPQ(std::map<std::string, BikePtr> data);

#endif // FUNCTIONALITIES_H

#include "Functionilities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"

void CreateObjects(Container &data)
{
    data[0] = std::make_shared<Car>(
        "c101",
        779000.0f,
        "Dizer",
        std::make_shared<Engine>(300, 110.0f),
        CarType::SEDAN);
    data[1] = std::make_shared<Car>(
        "c102",
        1290000.0f,
        "City",
        new Engine(330, 150.0f),
        CarType::SEDAN);
    data[2] = std::make_shared<Car>(
        "c103",
        2122000.0f,
        "XUV700",
        new Engine(430, 190.0f),
        CarType::SUV);
}


int totalHorsePower(const Container &data)
{
    if (data.empty())
        throw EmptyContainerException("Data is Empty");
    
    int hp = 0;
    for(const CarPointer& c :data){
        hp += c->engine()->horsePower();
    }
    return hp;
}

bool isAllCarAbove700K(const Container &data)
{
    if (data.empty())
        throw EmptyContainerException("Data is Empty");
    
    for(const CarPointer& c : data){
        if(c->price()<=700000.0f) return false;
    }
    return true; //reaching the point mean no car has price below 7 Lacs
}

Engine *enginePointerToMinPrice(const Container &data)
{
    if (data.empty())
        throw EmptyContainerException("Data is Empty");

    float min_price = data[0]->price();
    Engine* e = data[0]->engine();

    for(const CarPointer& c : data){
        if(c->price()<min_price){
            min_price = c->price();
            e=c->engine();
        }
    }
    return e;
}

float avgEngineTorque(const Container &data)
{
    if (data.empty())
        throw EmptyContainerException("Data is Empty");
    
    float avgVal {0.0f};
    for(const CarPointer& c : data){
        avgVal += c->engine()->torque();
    }

    return avgVal/data.size();
}

std::string findCarModelByID(const Container &data, const std::string carID)
{
    if (data.empty())
        throw EmptyContainerException("Data is Empty");
    
    for(const CarPointer& c : data){
        if(c->id()==carID) return c->model();
    }
    throw IdNotFoundException("Id not found");
}





/*

    A basic layout of a smart pointer
                                            HEAP
                                            0x100h
                                            [  101  |  Harshit  |  80000.0f]
        Stack Memory
        [
            mptr
            [    0x100h    ]
            ....
            ....
            ....
        ]
        <----------shared pointer--------->














*/
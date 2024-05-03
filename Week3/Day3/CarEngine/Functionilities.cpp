#include "Functionilities.h"



void CreateObjects(Container &data)
{
    data[0] = new Car(
        "c101",
        779000.0f,
        "Dizer",
        new Engine(300, 110.0f),
        CarType::SEDAN);
    data[1] = new Car(
        "c102",
        1290000.0f,
        "City",
        new Engine(330, 150.0f),
        CarType::SEDAN);
    data[2] = new Car(
        "c103",
        2122000.0f,
        "XUV700",
        new Engine(430, 190.0f),
        CarType::SUV);
}

void DeleteObjects(Container &data)
{
    if(data.empty()) throw EmptyContainerException("Data is Empty\n",std::future_errc::no_state);

    for (Car *c : data)
    {
        delete c->engine(); //
        delete c;
    }
}

int totalHorsePower(const Container &data)
{
    if(data.empty()) throw EmptyContainerException("Data is Empty\n",std::future_errc::no_state);
    int hp = 0;
    for (Car *c : data)
    {
        hp += c->engine()->horsePower();
    }
    return hp;
}

bool isAllCarAbove700K(const Container &data)
{
    if(data.empty()) throw EmptyContainerException("Data is Empty\n",std::future_errc::no_state);
    for (Car *c : data)
    {
        if (c->price() <= 700000.0f)
            return false;
    }
    return true; // reaching the point mean no car has price below 7 Lacs
}

Engine *enginePointerToMinPrice(const Container &data)
{
    if(data.empty()) throw EmptyContainerException("Data is Empty\n",std::future_errc::no_state);

    float min_price = data[0]->price();
    Engine *e = data[0]->engine();

    for (Car *c : data)
    {
        if (c->price() < min_price)
        {
            min_price = c->price();
            e = c->engine();
        }
    }
    return e;
}

float avgEngineTorque(const Container &data)
{

    if(data.empty()) throw EmptyContainerException("Data is Empty\n",std::future_errc::no_state);
    float avgVal{0.0f};
    for (Car *c : data)
    {
        avgVal += c->engine()->torque();
    }

    return avgVal / data.size();
}

std::string findCarModelByID(const Container &data, const std::string carID)
{
    if(data.empty()) throw EmptyContainerException("Data is Empty\n",std::future_errc::no_state);
    for (Car *c : data)
    {
        if (c->id() == carID)
            return c->model();
    }
}

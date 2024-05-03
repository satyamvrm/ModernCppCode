#include "Functionalities.h"

void createObjects(BrandContainer &brands, CarContainer &cars)
{
    cars.push_back(new Car(4, 10, 4, ChassisType::CARBON_FIBER));
    cars.push_back(new Car(5, 20, 4, ChassisType::STEEL));
    cars.push_back(new Car(6, 30, 4, ChassisType::CARBON_FIBER));
    cars.push_back(new Car(7, 40, 4, ChassisType::STEEL));
    cars.push_back(new Car(10, 50, 4, ChassisType::STEEL));
    cars.push_back(new Car(2, 60, 4, ChassisType::CARBON_FIBER));
    cars.push_back(new Car(1, 70, 4, ChassisType::CARBON_FIBER));
    cars.push_back(new Car(2, 80, 4, ChassisType::STEEL));
    cars.push_back(new Car(4, 90, 4, ChassisType::STEEL));

    brands.push_back(std::make_shared<Brand>(BrandType::CONSUMER, "A",
                                             std::array<std::reference_wrapper<Car>, 3>{*cars[0], *cars[1], *cars[2]}));
    brands.push_back(std::make_shared<Brand>(BrandType::TRANSPORT, "B",
                                             std::array<std::reference_wrapper<Car>, 3>{*cars[4], *cars[5], *cars[6]}));
    brands.push_back(std::make_shared<Brand>(BrandType::SPECIAL, "C",
                                             std::array<std::reference_wrapper<Car>, 3>{*cars[7], *cars[8], *cars[3]}));
}

void DisplayObjects(BrandContainer &data)
{
    for (auto c : data)
    {
        std::cout << *c << '\n';
    }
}

std::vector<std::string> BrandByBrandType(BrandContainer &data, BrandType t)
{
    std::vector<std::string> r;
    for (auto a : data)
    {
        if (a->brandType() == t)
            r.push_back(displayEnum(a->brandType()));
    }
    return r;
}

std::vector<Car *> CarsAboveThreshold(BrandContainer &data, float p)
{
    std::vector<Car *> r;
    for (auto a : data)
    {
        for (auto c : a->cars())
        {
            if (c.get().price() > p)
            {
                r.push_back(&c.get());
            }
        }
    }
    return r;
}

ChassisType ChassisTypeOfCheapestCar(BrandContainer &data)
{
    Car *t;
    for (auto i : data)
    {
        for (auto j : i->cars())
        {
            t = &j.get();
            if (t->price() > j.get().price())
            {
                t = &j.get();
            }
        }
    }
    return t->ctype();
}

bool allHave4seats(BrandContainer &data)
{
    bool flag{true};
    for (auto i : data)
    {
        for (auto j : i->cars())
        {
            if (j.get().seatCount() < 4)
                flag = false;
        }
    }
    return flag;
}

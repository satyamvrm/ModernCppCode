#include "Operations.h"

std::unique_ptr<Operations> Operations::_soloObject{nullptr};

std::unique_ptr<Operations> &Operations::getInstance()
{
    if (!_soloObject)
        _soloObject = std::unique_ptr<Operations>(new Operations());

    return _soloObject;
}

void Operations::createObject()
{
    engins.push_back(Engine("E-101", 120, 150, EngineType::CRDI));
    engins.push_back(Engine("E-102", 140, 180, EngineType::TURBOCHARED));
    engins.push_back(Engine("E-103", 160, 250, EngineType::MPFI));
    engins.push_back(Engine("E-104", 240, 190, EngineType::TURBOCHARED));
    engins.push_back(Engine("E-105", 180, 200, EngineType::MPFI));

    cars.push_back(std::make_shared<Car>("C-101", 120000.0f, std::ref(engins[0])));
    cars.push_back(std::make_shared<Car>("C-102", 130000.0f, std::ref(engins[1])));
    cars.push_back(std::make_shared<Car>("C-103", 140000.0f, std::ref(engins[2])));
    cars.push_back(std::make_shared<Car>("C-104", 150000.0f, std::ref(engins[3])));
    cars.push_back(std::make_shared<Car>("C-105", 160000.0f, std::ref(engins[4])));
}

void Operations::display()
{
    for (auto x : cars)
        std::cout << *x << '\n';
}

std::vector<std::reference_wrapper<Engine>> Operations::ReturnEngineReferance()
{
    std::vector<std::reference_wrapper<Engine>> result;
    std::for_each(cars.begin(), cars.end(), [&](CarPtr &c)
                  { result.push_back(c->carEngine()); });
    return result;
}

bool Operations::allAbove()
{
    return std::all_of(cars.begin(), cars.end(), [](CarPtr &c)
                       { return c->carEngine().get().engineTorque() >= 120; });
}

int Operations::avgHorsepower(float price)
{
    int count{0};
    int sum = std::accumulate(
        cars.begin(),
        cars.end(),
        0.0f,
        [&](float val, CarPtr &c)
        {
            if (c->price() > price){
                count++;
                return val + c->carEngine().get().engineTorque();
            }
            else
                return val;
        });
        return sum/count;
}

EngineType Operations::findEngineType(std::string reg)
{
    auto itr = std::find_if(
        cars.begin(),
        cars.end(),
        [&](CarPtr& c){
            return c->carRegNum() == reg; 
        }
    );
    return itr->get()->carEngine().get().engineType();
}

std::reference_wrapper<Engine> Operations::highestTorque()
{
    auto itr = std::max_element(
        cars.begin(),
        cars.end(),
        [](CarPtr& c,CarPtr& c2){
            return c->carEngine().get().engineTorque() < c2->carEngine().get().engineTorque();
        }
    );
    return itr->get()->carEngine();
}

#include "Functionalities.h"
#include <variant>

void createObject(Container& data)
{
    data.push_back(new Engine(EngineType::DIESEL, 100, 1900));
    data.push_back(new Engine(EngineType::PETROL, 990, 9000));
    data.push_back(new Engine(EngineType::DIESEL, 200, 8000));
    // data.push_back(new Engine(EngineType::DIESEL, 12, 21));
}

std::function<int(Container&)> avgHP = [](Container& data) -> int {
    int count{0},sum{0};
    for(auto t : data){
        if(std::holds_alternative<Engine*>(t)){
            Engine* temp = std::get<Engine*>(t);
            sum+=temp->hp();
            count++;
        }
    }
    return sum/count;
};
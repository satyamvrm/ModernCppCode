#include "Functionalities.h"

void createObjects(Container &data)
{
    data.push_back(
        std::make_shared<User>(
            "a",10,100.0f
        )
    );
    data.push_back(
        std::make_shared<User>(
            "b",11,110.0f
        )
    );
    data.push_back(
        std::make_shared<User>(
            "c",12,120.0f
        )
    );
    data.push_back(
        std::make_shared<User>(
            "d",10,140.0f
        )
    );
}

void displayObjects(Container &data)
{
    for(auto c:data)
    std::cout<<*c<<'\n';
}

std::function<int(Container&)> AverageUserIncome = [](Container& data){
    float sum{0.0f};
    for(auto c: data){
        sum+=c->income();
    }
    return sum/data.size();
};

std::function<std::list<std::string>(Container&,int)> giveUserID = [](Container& data, int age){
    std::list<std::string> newData;
    for(auto c : data){
        if(c->age()==age) newData.push_back(c->name());
    }
    return newData;
};


std::function<std::shared_ptr<User>(Container& data)> minimumUserAge = [](Container& data){
    std::shared_ptr<User> rst = data.front();
    for(auto c:data){
        if(c->age()<rst->age()) rst = c;
    }
    return rst;
};

#include<iostream>
#include"Functionalities.hpp"
int main() {

    EngineContainer engineData;
    VehiclePriorityQueue vehiclePQ;

    CreateObjects(engineData, vehiclePQ);

    // std::visit([](auto&& val){std::cout<<*val<<std::endl;}, vehiclePQ.top());
    // vehiclePQ.pop();
    // std::visit([](auto&& val){std::cout<<*val<<std::endl;}, vehiclePQ.top());
    // vehiclePQ.pop();
    // std::visit([](auto&& val){std::cout<<*val<<std::endl;}, vehiclePQ.top());
    // vehiclePQ.pop();
    // std::visit([](auto&& val){std::cout<<*val<<std::endl;}, vehiclePQ.top());
    // vehiclePQ.pop();

    while(!vehiclePQ.empty()) {
        std::visit([](auto&& val){std::cout<<*val<<std::endl;}, vehiclePQ.top());
        vehiclePQ.pop();
    }


}
#include<iostream>
#include"Functionalities.hpp"

int main() {

    EngineContainer engineData;
    VehiclePriorityQueue vehicleData;
    std::vector<std::variant<CarPointer, BikePointer>> vehicleVariantVector;
    
    VehiclePriorityQueueMin vData;

    VehiclePriorityQueueMin v = vData;
    
    // VehiclePriorityQueueMin vehicleDataMin(vehicleVariantVector.begin(), vehicleVariantVector.end());

    // CreateObjects(engineData, std::ref(vehicleData));
    CreateObjects(engineData, vData);
    // CreateObjectsMin(engineData, vehicleVariantVector);


    std::visit([](auto&& val){std::cout<<*val<<std::endl;}, vData.top());
    vData.pop();
    std::visit([](auto&& val){std::cout<<*val<<std::endl;}, vData.top());
    vData.pop();
    std::visit([](auto&& val){std::cout<<*val<<std::endl;}, vData.top());
    vData.pop();
    std::visit([](auto&& val){std::cout<<*val<<std::endl;}, vData.top());
    vehicleData.pop();

    // std::cout<<"--------------------------------------------------"<<std::endl;

    // std::visit([](auto&& val){std::cout<<*val<<std::endl;}, vehicleDataMin.top());
    // vehicleDataMin.pop();
    // std::visit([](auto&& val){std::cout<<*val<<std::endl;}, vehicleDataMin.top());
    // vehicleDataMin.pop();
    // std::visit([](auto&& val){std::cout<<*val<<std::endl;}, vehicleDataMin.top());
    // vehicleDataMin.pop();
    // std::visit([](auto&& val){std::cout<<*val<<std::endl;}, vehicleDataMin.top());
    // vehicleDataMin.pop();

}
#include<bits/stdc++.h>
#include "Car.h"
#include "Engine.h"
#include "IdNotFoundException.h"
#include "EmptyContainerException.h"
#include "CarType.h"
#include "Functionilities.h"

int main(){
    Container data;    
    CreateObjects(data);
    try{
        int ans = totalHorsePower(data);
        std::cout<<"Total horse power is "<<ans;
        float result = avgEngineTorque(data);
        std::cout<<"\nAverage Value is "<<result;
        std::string model = findCarModelByID(data,"c101");
        std::cout<<"\nModel for give id found "<<model;
        bool flag=isAllCarAbove700K(data);
        if(flag){
            std::cout<<"\nAll are above 7 lacs";
        }else{
            std::cout<<"\nSome are below 7 lacs";
        }
        Engine* e = enginePointerToMinPrice(data);
        std::cout<<"\nEngine Found : "<<*e<<"\n";
        // DeleteObjects(data);
    }
    catch(const EmptyContainerException &ex){
        std::cout << ex.what() << "\n";
    }
    catch(const IdNotFoundException &ex){
        std::cout<<ex.what()<<"\n";
    }
    return 0;
}
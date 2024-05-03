#include "Functionalities.h"
#include<thread>
#include<future>

int main(){
    Container data;
    std::thread t(&createObjects, std::ref(data));
    t.join();
    std::cout<<"All the objects in list are : "<<'\n';
    std::thread displayT(&displayObjects,std::ref(data));
    displayT.join();
    try{
        std::cout<<"\nThe Average Milage of all automobile :- ";
        std::thread t1(&averageMilage,std::ref(data));
    t1.join();
    }catch(EmptyContainerException& e){
        std::cerr<<e.what()<<'\n';
    }

    try{
        std::cout<<"\nThe Count of Private automobile :- ";
        // std::cout<<countInstanceAutomobileType(data,AutomobileType::PRIVATE)<<'\n';
        std::thread t2(&countInstanceAutomobileType,std::ref(data),AutomobileType::PRIVATE);
    t2.join();
    }catch(EmptyContainerException& e){
        std::cerr<<e.what()<<'\n';
    }

    try{
        std::cout<<"\nAny instance above 20000 in automobile :- ";
        // std::cout<<anyInstanceAbove20000(data)<<'\n';
        std::thread t3(&anyInstanceAbove20000,std::ref(data));
    t3.join();
    }catch(EmptyContainerException& e){
        std::cerr<<e.what()<<'\n';
    }
}
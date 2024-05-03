#include "Functionalities.h"
#include "ConfirmedTrip.h"

int main(){
    Container data,d;
    createObjects(data);
    displayObjects(data);
    try{
        std::cout<<"The Average Travel Time :- "<<findAverageTravelTime(data)<<'\n';
        std::cout<<"The Minimum Travel Time :- "<<findMinimumTimeTravel(data)<<'\n';
        std::cout<<"The count of Prime Cars :- "<<findCount(data,CarType::PRIME)<<'\n';
        std::cout<<"The count of Prime Cars :- "<<findCount(d,CarType::PRIME)<<'\n';
    }catch(EmptyData& e){
        std::cerr<<e.what()<<'\n';
    }
}
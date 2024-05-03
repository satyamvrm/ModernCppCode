#include "Functionalities.h"

int main(){
    Container data;
    createObjects(data);
    displayObjects(data);
    FunctionContainer fns = {over50SeatsFlights,highestEntries};
    try{
        std::cout<<"Total seat count :- "<<highestEntries(data)<<'\n';
        std::cout<<"over50SeatsFlights :- "<<over50SeatsFlights(data)<<'\n';
        std::cout<<"highestFlightSeats :- "<<highestFlightSeats(data)<<'\n';
        std::cout<<"longestFlightDistace :- "<<longestFlightDistace(data)<<'\n';
        std::cout<<"\n\nOperations :- \n";
        operations(data,fns);

    }catch(std::runtime_error& e){
        std::cerr<<e.what()<<'\n';
    }
}
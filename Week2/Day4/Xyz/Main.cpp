#include "Functionalities.h"

int main(){
    Container data{1,2,3,4,5};
    try{
        Adaptor(lfn1,data);
        Adaptor(lfn2,data);
        Adaptor(lfn3,data);
        Adaptor(
            [](Container& data){
                int sum{0};
                for(int d : data) sum+=d;
                std::cout<<"Sum of first 3 element :- "<<sum<<'\n';
            }, data
        );
    }
    catch(std::runtime_error& e){
        std::cerr<<e.what()<<'\n';
    }
}
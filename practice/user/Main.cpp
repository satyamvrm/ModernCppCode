#include "Functionalities.h"

int main(){
    Container data;
    createObjects(data);
    displayObjects(data);
    std::cout<<"AverageUserIncome :- "<<AverageUserIncome(data)<<'\n';
    std::list<std::string> names = giveUserID(data,10);
    std::cout<<"names : ";
    for(auto c : names ) std::cout<<c<<" ";
    std::cout<<"\n";
    std::cout<<"minimumUserAge :- "<<*minimumUserAge(data)<<'\n';
}
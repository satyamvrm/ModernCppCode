#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<vector>
#include "Major.h"
#include <memory>


using Container = std::vector<std::shared_ptr<Major>>;

void createObject(Container& data){
    Minor m;
    data.push_back(std::make_shared<Major>(m));
    data.push_back(std::make_shared<Major>(m));
    data.push_back(std::make_shared<Major>(m));
}

/* 
Using Lambda function
void getValues(Container& data, int n1, int n2){

    data[0]->Operation(
        [&](int n1,int n2){data[0]->minor().get().sum(n1,n2);}
        ,n1,n2);
    
    data[1]->Operation(
        [&](int n1,int n2){data[1]->minor().get().multiply(n1,n2);}
        ,n1,n2);
    
    data[2]->Operation(
        [&](int n1,int n2){data[2]->minor().get().subtract(n1,n2);}
        ,n1,n2);

} */

void getValues(Container& data, int n1, int n2){

    data[0]->Operation(
        [&](int n1,int n2){data[0]->minor().get().sum(n1,n2);} ,10,n1);
    
    data[1]->Operation(
        [&](int n1,int n2){data[1]->minor().get().multiply(n1,n2);}
        ,n1,n2);
    
    data[2]->Operation(
        [&](int n1,int n2){data[2]->minor().get().subtract(n1,n2);}
        ,n1,n2);

}

#endif // FUNCTIONALITIES_H
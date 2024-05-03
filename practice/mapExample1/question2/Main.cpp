#include "Functionalities.h"
#include<future>

int main(){
    Container data;
    createObjects(data);
    std::cout<<"All data in the list :- ";
    displayObjects(data);

    try{
        std::cout<<"\nCount of Project having budget above 5K : ";
        std::future<int>t1 =  std::async(&countBudgetOver5000,std::ref(data));
        std::cout<<t1.get()<<'\n';
    }catch(EmptyContainerException& e){
        std::cerr<<e.what()<<'\n';
    }

    try{
        std::cout<<"\nWeather all employees have salary above 10K : ";
        std::future<bool> t2 = std::async(&allSalaryAbove10K,std::ref(data));
        std::cout<<std::boolalpha<<t2.get()<<'\n';
    }catch(EmptyContainerException& e){
        std::cerr<<e.what()<<'\n';
    }

    try{
        std::cout<<"\nAverage Tax Exemption of all employess : ";
        std::future<float> t3 = std::async(&AverageTaxExemption,std::ref(data));
        std::cout<<t3.get()<<'\n';
    }catch(EmptyContainerException& e){
        std::cerr<<e.what()<<'\n';
    }

    try{
        int n{0};
        std::cout<<"\n Enter the Number of instance to print : ";
        std::cin>>n;
        firstNInstances(data,n);
    }catch(EmptyContainerException& e){
        std::cerr<<e.what()<<'\n';
    }
}
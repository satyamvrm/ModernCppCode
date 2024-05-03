#include<iostream>
#include "classA.h"
#include "classB.h"
#include<list>
#include<variant>
#include<memory>

using vType = std::variant<std::shared_ptr<classA>,std::shared_ptr<classB>>;
using Container = std::list<vType>;

void printCommon(Container& arr){
    for(vType temp : arr){
        std::visit(
            [](auto && v){
                std::cout<<v->getCommon()<<'\n';
            },temp
        );
    }
}

void nonCommon(Container& arr){
    for(vType v : arr){
        if(std::holds_alternative<std::shared_ptr<classA>>(v)){
            std::shared_ptr<classA> temp = std::get<0>(v);
            std::cout<<"A :- "<<temp->getA();
        }
        else{
            std::shared_ptr<classB> temp = std::get<1>(v);
            std::cout<<"B :- "<<temp->getB();
        }
    }
}

int main(){
    Container arr = {
        std::make_shared<classA>(1,2),
        std::make_shared<classA>(3,4),
        std::make_shared<classB>(5,4),
        std::make_shared<classB>(3,6)
    };
    printCommon(arr);
    nonCommon(arr);
}
#include "Car.h"
#include "Bus.h"
#include "Bike.h"
#include<variant>
#include<vector>
#include<memory>

using vType = std::variant<std::shared_ptr<Car>,std::shared_ptr<Bike>,std::shared_ptr<Bus>>;
using Container = std::vector<vType>;

void print(Container &arr){
    for(auto c : arr){
        std::visit(
            [](auto && v){
                std::cout<<*v<<'\n';
            },c
        );
    }
}

void printUncommon(Container& arr){
    for(auto c : arr){
        if(std::holds_alternative<std::shared_ptr<Car>>(c)){
            std::shared_ptr<Car> temp = std::get<0>(c);
            std::cout<<"Number of seats :- "<<temp->getNoOfSeats()<<'\n';
        }
        else if(std::holds_alternative<std::shared_ptr<Bike>>(c)){
            std::shared_ptr<Bike> temp = std::get<1>(c);
            std::cout<<"Bike's break type :- "<<temp->breakType()<<'\n';
        }
        else{
            std::shared_ptr<Bus> temp = std::get<2>(c);
            std::cout<<"Bus type :- "<<temp->busType()<<'\n';
        }
    }
}

int main(){
    std::shared_ptr<Car> car1 = std::make_shared<Car>("BMW","20BH283H",4);
    std::shared_ptr<Car> car2 = std::make_shared<Car>("Alto","20BH283E",4);
    std::shared_ptr<Bike> bike1= std::make_shared<Bike>("Hero","22BH3847H","Disk");
    std::shared_ptr<Bike> bike2= std::make_shared<Bike>("Hero","22BH3847I","Power");
    std::shared_ptr<Bus> bus1 = std::make_shared<Bus>("Volvo","22BH7403F","Government");
    std::shared_ptr<Bus> bus2 = std::make_shared<Bus>("Volvo","22BH7403H","Private");

    Container arr{car1,bike1,bus1,bike2,car2,bus2};

    std::cout<<"Common members\n";
    print(arr);
    std::cout<<"\nUn-common members\n";
    printUncommon(arr);
}
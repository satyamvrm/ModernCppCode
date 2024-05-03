#include<iostream>

enum class EngineType{
    DIESEL,
    PETROL
};

class EngineDummy
{
private:
    /* data */
    int _horsepower;
    EngineType _type;

public:
    EngineDummy(int hp, EngineType type) :_horsepower{hp}, _type{type}{}
    ~EngineDummy() {}

    friend std::ostream &operator<<(std::ostream &os, const EngineDummy &rhs) {
        std::string t{""};
        if(rhs._type == EngineType::DIESEL) t="Diesel";
        else t="Petrol";

        os << "_horsepower: " << rhs._horsepower
           << " _type: " << t;
        return os;
    }
    
};

int main(){
    EngineDummy e1(700,EngineType::PETROL);
    std::cout<<   e1;
}
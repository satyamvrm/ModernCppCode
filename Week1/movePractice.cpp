#include<iostream>
#include<vector>
class Engine
{
private:
    int n;
public:
    Engine(/* args */) {}
    ~Engine() {}
    Engine(int a):n{a}{}

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
        os << "n: " << rhs.n;
        return os;
    }
};

class Car{
    private:
        int b{0};
        Engine* e{nullptr};
    public:
        Car()=default;
        ~Car()=default;

        int getB() const { return b; }
        void setB(int b_) { b = b_; }

        Engine* getE() const { return e; }
        void setE(Engine* e_) { e = e_; }
        
        Car(int a, Engine* e): b{a}, e{e}{
        }

        friend std::ostream &operator<<(std::ostream &os, const Car &rhs) {
            os << "b: " << rhs.b
               << " e: " << *rhs.e;
            return os;
        }

};

int main(){
    std::vector<Car*> cars, cars2;
    cars.push_back(new Car(101,new Engine(11)));
    cars.push_back(new Car(102,new Engine(12)));
    cars.push_back(new Car(103,new Engine(13)));
    cars.push_back(new Car(104,new Engine(14)));
  
    for(Car* c : cars){
        std::cout<<*c<<std::endl;
    }
    
    std::cout<<"\n\n\n";

    cars2.push_back(std::move(cars.back()));
    // cars.push_back(std::move(cars[0]));
    for(Car* c : cars2){
        std::cout<<*c<<std::endl;
    }
    std::cout<<"\n\n\n";

    for(Car* c : cars){
        std::cout<<*c<<std::endl;
    }

    std::cout<<"\n\n\n";

    std::cout<<cars.size();
    std::cout<<cars2.size();
    

}
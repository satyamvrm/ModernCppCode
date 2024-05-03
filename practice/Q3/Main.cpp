#include "Functionalities.h"

int main()
{
    Container data;
    CreateObject(data);

    try{
        ClassType t = ClassType::EvCar_TYPE;
        std::future<void> t1 = std::async(&NInstances,std::ref(data),std::ref(t),1);
        t1.get();

        std::future<bool> t2 = std::async(&TankCapacity,std::ref(data));
        std::cout<<"All Tank :- "<<t2.get()<<'\n';

        std::future<void> t3 =std::async(&CountICECar,std::ref(data));
        t3.get();

        std::future<Container> t4 = std::async(&BatteryThreshold,std::ref(data),420);
        Container result = t4.get();
        std::cout<<"Batter cap over 420 :- \n";
        for(auto t:result){
            if(std::holds_alternative<EvCarPointer>(t)){
                auto temp = std::get<EvCarPointer>(t);
                std::cout<<*temp<<'\n';
            }
        }

        std::future<void> t5 = std::async(&Display,std::ref(data));
        t5.get();

        std::future<void> t6 = std::async(&DisplayNth,std::ref(data),3);
        t6.get();
    }
    catch(...){
        std::cout<<"Sorry Time nhi hai abhi\n";
    }
}
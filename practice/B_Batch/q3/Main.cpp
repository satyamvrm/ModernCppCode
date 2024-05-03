#include "Functionalities.h"
#include<future>

#define line std::cout<<"-----------------------------------------------\n";

int main()
{
    Container data;
    createObjects(data);
    line;
    display(data);
    line;
    std::cout << std::boolalpha << allSameGear(data)<<'\n';
    line;
    std::optional<std::vector<CarPtr>> res = findInstances(data,CarType::SEDAN);
    if(res.has_value()){
        for(auto c : res.value()){
            std::cout<<*c<<'\n';
        }
    }
    line;
    std::cout<<"Price of lowest top speed : "<<lowestSpeedPrice(data)<<'\n';
    line;
    std::cout<<"Top RPM of C-103 : "<<topRPMbyID(data,"C-103")<<'\n';
    line;
    std::future<int> t5 = std::async(countabove,std::ref(data),120000);
    std::cout<<"Count : "<<t5.get()<<'\n';
    line;
}
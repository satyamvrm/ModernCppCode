#include "Functionalities.h"
#include "customException.h"
#include<stdexcept>
int main(){
    std::vector<std::shared_ptr<Car>> data;
    std::vector<std::shared_ptr<Car>> data2;
    CreateObject(data);
    DisplayObjects(data);
    try{
        std::cout<<"\n";
    int n= TotalHorsePower(data);
    std::cout<<"\n\ntotal horse power : "<<n<<'\n';
    
    n= TotalHorsePower(data2);
    std::cout<<"\n\ntotal horse power : "<<n;
    }catch(customException& e){
        std::cerr<<e.what();
    }
    return 0;
}
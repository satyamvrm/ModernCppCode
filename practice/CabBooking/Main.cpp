#include"Functionalities.h"

int main(){
    Container data,data2;
    createObjects(data);
    displayObjects(data);

    try{
        std::cout<<"\n\nBooking Id :";
        std::cout<<*findBookingById(data);
        std::cout<<"\n\nAbove 1000 : "<<(allAbove1000(data2)?" Yes ":" No ");
        std::cout<<"\n\nnInstance : ";
        Container newData;
        newData = nInstance(data,2);
        displayObjects(newData);
    }catch(EmptyData& e){
        std::cerr<<e.what()<<'\n';
    }
}
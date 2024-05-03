#include "functional"
#include "Operation.h"

int main(){
    std::shared_ptr<Operation> ptr = Operation::getInstance();
    ptr->createObjects();

    std::promise<int> pr;
    std::future<int> ft = pr.get_future();
    
    std::future<PaymentMode> t1 = std::async(&Operation::paymentModeById,ptr,"102");
    std::future<std::array<RideType,2>> t2 = std::async(&Operation::MaximumMinimumRideType,ptr);
    std::future<std::vector<std::string>> t3 = std::async(&Operation::FirstNInstances,ptr,std::ref(ft));

    int n=2;
    pr.set_value(n);

    PaymentMode payment = t1.get();
    std::array<RideType,2> result = t2.get();
    std::vector<std::string> result2 = t3.get();

    std::cout<<"First function :- "<<static_cast<int>(payment);
    std::cout<<"Second Function :- "<<static_cast<int>(result[0])<<" "<<static_cast<int>(result[1]);
    std::cout<<"Third function :- ";
    for(auto x : result2){
        std::cout<<x<<'\n';
    }


}
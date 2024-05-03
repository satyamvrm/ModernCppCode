#include "Employee.h"
 
 
 
 
template<typename T, typename... Args>
T Relay(Args&&... args){
    return T(std::forward<Args>(args)...);
}
 
 
 
 
int main(){
   Employee emp = Relay<Employee>("Satyam",600000.0f,"12","Trainee",23);
   std::cout<<emp;
}
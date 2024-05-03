#include<iostream>
#include<vector>

/* 
    number passed to the magic must always be temprory value or moved 
    values capture parameter by refrence
*/

void Magic(std::vector<int>&& data){

}

int main(){
    std::vector<int> value {10,20,30,40,50};
    std::cout<<value.size()<<"\n";
    Magic(std::move(value));
    std::cout<<value.at(3)<<"\n";
}

/* 
    we create vector in main(scope in main)
    HEAP
    [10,20,30,40,50 |   |   |   |]
    ^            ^             ^
    |            |             |
    |            |             |
    [0x100   | 0x116 |       0x132]
    <---------main variable------->
    <----------24 bytes----------->

 */

/* 
    1) program starts because os schedule the process
    2) main function is executed as a thread by the os
    3) vector of integer vues is create d in the scope of main
        a. heao allocation happens and vector gets space on heap
        b. pointer to start, end and capacity are recorded in the vector object "value" in main
    4) Magic(std::move(value))
        a. std::move(value) : It converts lvalue into rvalue(tells the compiler "value" vector can be prepared for move)
        b. now vector value is treated as a rvalue 
        so Magic (std::move(value)) becomes Magic()
 */
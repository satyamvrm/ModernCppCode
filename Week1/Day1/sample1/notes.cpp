/* const keyword
1 : const applied to the token on its immediate left.
if there is noting to the left of const, apply const on the token to its immidiate right

2: pointer symbol * is considered a separate token */

#include<bits/stdc++.h>
using namespace std;

class dummy
{
private:
    /* data */
    int _id;
    float _salary;
public:
    dummy(int id, float sal):_id(id),_salary(sal){} 
    ~dummy() =default;

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

};

int main(){
    //const with a non pointer premitive variable
    const int n1=10; //n1 is a constant int
    int const n2 = 20; //n2 is a constant int
 
    //pointer with primitive 
    //2a 
    int n3=99;
    int n4=89;
    const int * ptr = &n3; //ptr is a pointer to constant int
    //*ptr = 4 error
    //ptr = &n4 is ok
    
    //2b
    int * const ptr2 = &n4; //ptr2 is a const pointer to an integer
    //*ptr2 = 100 is ok
    //ptr = &n4 will error

    //2c
    const int * const ptr3 = &n3;
    //combination of 2a and 2b both data and pointer is constant



    //Const on a stack object
    const dummy d1(101,6799.0f);
    // d1._id = 12; //will give error
    //d1.setSalary(938.0f) //will give error
    
    //getter const is use because only constant function can be called by constant objects

    return 0;
}


/* 

    part 1 :
        Essentials of MODERN CPP

    part 2 :
        Functional programming in MCpp

    part 3 :
        Concurrency in Modern cpp
    
    part 4 :
        STL Ultra Pro Max


 */
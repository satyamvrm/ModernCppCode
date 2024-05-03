#include<vector>
#include<iostream>
#include<functional>

/*
    No.     Identifier-Name     Address     Content     Alternative-Name
    1       n1                  0x99H       99          ref, argRef
    2       data                0x43H       10          ref, refRef
*/

void magic(int & agrRef){

}

int main(){
/*     int n1=99;
    int& ref = n1; //creating a referance 
    magic(n1); //passing by referance

    // Referances do not hold memory so the is no value to logic apply logic on...... imp
    // no container for the referances
    // A referance does not exist anywhere in the memory
    alternate name for anything 
    // int& arr[] = {ref} //will give error
    // std::vector<int&> value{ref}; 

    int data=10;
    int& ref2 = data; //creating a referance
    int& refRef = ref2; //creating a referance of referance which is basically impossible this will give the referance of data itself
 */

    int data{10};
    std::reference_wrapper<int> r {data};
    
}

/*
    Fn(int a);
    Fn(10);         int a=10;

    previously:
        A pointer when stored in an object creates representation of a pointer (smart pointer)

        A referance stored in an object internally creates representation of a referance called referance_wrapper.
*/
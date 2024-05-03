/* 
    1. It enhances the language with a brand new feature
    2. 
        a. It improve an existing feature //(pointers---->smart pointers)
        b. It improve as exisitng feature inspired from C lang. which had a drawback(enum class)
*/


// NULL
#include<iostream>

int main(){
    int *ptr = NULL; //0x000H
    int n1 = NULL;
    std::cout<<ptr<<'\n';
    // NULL : 0  0L  0o0  0b0000  0x0000 : no-datatype 

    int *ptr2 = nullptr;
    int n2 = nullptr;
    std::cout<<ptr2<<'\n';
    // nullptr can only be used with pointers not with anything else

}

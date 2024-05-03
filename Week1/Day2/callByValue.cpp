#include<bits/stdc++.h>
using namespace std;

/* 
    int &a : reference
    &a : no data type to the left of a : address(pointer)
 */

void magic(int val){
    std::cout<<"Value in magic b4 modification "<<val<<"\n";
    std::cout<<"Address of value inside magic : s: "<<&val<<"\n";
    val=111;
    std::cout<<"Value in magic after modification in magic "<<val<<"\n";
}

void magic2(int &val){
    std::cout<<"Value in magic b4 modification "<<val<<"\n";
    std::cout<<"Address of value inside magic : s: "<<&val<<"\n";
    val=111;
    std::cout<<"Value in magic after modification in magic "<<val<<"\n";
}

void magic3(int* val){
    std::cout<<"Value in magic b4 modification "<<val<<"\n";
    std::cout<<"Address of value inside magic : s: "<<&val<<"\n";
    std::cout<<"Derefrencing data before "<<*val<<"\n";
    *val=111;
    std::cout<<"Value in magic after modification in magic "<<val<<"\n";
    std::cout<<"Derefrencing data after "<<*val<<"\n";
}

int main(){
    std::cout<<"\t\t\t---------------------Call-By-Value---------------------\t\n";
    int val = 110;
    std::cout<<"Value in magic b4 modification "<<val<<"\n";
    std::cout<<"Address of value inside magic : s: "<<&val<<"\n";
    magic(val);
    std::cout<<"Value in magic after modification out magic "<<val<<"\n\n\n";
    

    std::cout<<"\t\t\t---------------------Call-By-Refrence---------------------\t\n";
    int val2 = 110;
    std::cout<<"Val2ue in magic b4 modification "<<val2<<"\n";
    std::cout<<"Address of val2ue inside magic : s: "<<&val2<<"\n";
    magic2(val2);
    std::cout<<"Val2ue in magic after modification out magic "<<val2<<"\n\n\n";
    
    
    std::cout<<"\t\t\t---------------------Call-By-Pointer---------------------\t\n";
    int val3 = 110;
    std::cout<<"Val3ue in magic b4 modification "<<val3<<"\n";
    std::cout<<"Address of val3ue inside magic(same as content of data) : s: "<<&val3<<"\n";
    magic3(&val3);
    std::cout<<"Val3ue in magic after modification out magic "<<val3<<"\n";


    
    return 0;
}
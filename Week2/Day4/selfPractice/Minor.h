#ifndef MINOR_H
#define MINOR_H
#include<iostream>
class Minor
{
private:
    
public:
    //default constructor disabled
    Minor()=default;
    //default copy constructor disabled
    Minor(const Minor&) = delete;
    // default move constructor disabled 
    Minor(const Minor&&) = delete;
    // default assignment operator disabled 
    Minor &operator=(const Minor&) = delete; 
    // default move operator disabled
    Minor &operator=(const Minor&&) = delete; 
    // default distructor enabled 
    ~Minor()=default;

    void sum(int n1, int n2){
        std::cout<<n1+n2<<'\n';
    }

    void multiply(int n1, int n2){
        std::cout<<n1*n2<<'\n';
    }

    void subtract(int n1, int n2){
        std::cout<<abs(n1-n2)<<'\n';
    }

};

#endif // MINOR_H

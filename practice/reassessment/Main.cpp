#include "Functionalities.h"
#include <functional>
#include <iostream>
#include <future>

int main()
{
    Container data;
    createObject(data);
    std::cout<<"Avg HP :- "<<avgHP(data)<<'\n';
    
}
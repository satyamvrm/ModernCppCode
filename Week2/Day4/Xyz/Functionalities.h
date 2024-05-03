#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<functional>
#include<iostream>

using Container = std::vector<int>;
using FnTypes = std::function<void(Container&)>; 

void Adaptor(FnTypes fn, Container& data);

/* Extern is use to initalze in some file and assign in other 
auto will not work when we exernally declare lambda function */

extern FnTypes lfn1;
extern FnTypes lfn2;
extern FnTypes lfn3;

#endif // FUNCTIONALITIES_H

#include "Functionalities.h"

void Adaptor(FnTypes fn, Container &data)
{
    if(data.empty()) throw std::runtime_error("Data is empty");
    fn(data);
}


/* we don't use extern where we assign the variable we only use it when we initilize */

FnTypes lfn1 = [](Container& data){std::cout<<"First Element :- "<<data.front()<<'\n';};
FnTypes lfn2 = [](Container& data){std::cout<<"Last Element :- "<<data.back()<<'\n';};
FnTypes lfn3 = [](Container& data){std::cout<<"Vector Size :- "<<data.size()<<'\n';};

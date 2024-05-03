#ifndef MAJOR_H
#define MAJOR_H

#include "Minor.h"
#include<functional>

class Major
{
private:
    std::reference_wrapper<Minor> _minor;    

public:
    //default constructor disabled
    Major()=delete;
    //default copy constructor disabled
    Major(const Major&) = delete;
    // default move constructor disabled 
    Major(const Major&&) = delete;
    // default assignment operator disabled 
    Major &operator=(const Major&) = delete; 
    // default move operator disabled
    Major &operator=(const Major&&) = delete; 
    // default distructor enabled 
    ~Major()=default;

    Major(std::reference_wrapper<Minor> minor): _minor{minor}
    {}

    void Operation(std::function<void(int,int)> fn, int n1, int n2){
        fn(n1,n2);
    }

    std::reference_wrapper<Minor> minor() const { return _minor; }

};

#endif // MAJOR_H

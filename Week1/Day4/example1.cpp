#include <iostream>
#include <memory>

class example1
{
private:
    /* data */
    std::string _name;
    int _id;

public:
    example1(int id, std::string name) {}
    ~example1() {}
};

void createObject()
{
    // example1* obj = new example1(10,"Harshit");
    std::shared_ptr<example1> sptr{std::make_shared<example1>(10, "Satyam")};

    
    // delete obj;
}

float div(){
    float n1{0};
    std::cin >> n1;
    if (n1 == 0)
        throw std::runtime_error("DivideByZeroException");
    std::cout  << 10 / n1;
}

int main()
{
    try
    {
        div();
        // createObject();
    }catch(std::exception &ex){
        std::cout<<ex.what();
    }
}

/*
    createObject()                      heap
            ------------------------>[   10   |  harshit  ]
    ex1     |                       0x100h
    [   0x100H   ]
    <--8 bytes-->
    0x11h        0x18h

    n1
    [    0    ]
    <-4 bytes->

 */

/*
        data : pointer ex1
        function which is guranteed to execute each time an object is distroyed: destructor
        action before data (ex1) is distroyed : heap deallocation using delete ex1


        smart pointer in modern c++:
        1. unique pointer
        2. shared pointer
        3. weak pointer (token which can convert to shareed ptr)





 */
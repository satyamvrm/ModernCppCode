#include <iostream>
#include<exception>

class Parent
{
private:
public:
    Parent() {}
    virtual void magic() = 0;
    ~Parent() {}
};

class Child : public Parent
{
private:
public:
    Child() {}
    virtual ~Child() {}
    void magic() override { std::cout << "Magic from child\n"; }
    void ChildDisplay() { std::cout << "Done\n"; }
};

int main()
{
    // int n1 = (float)"satyam";  //c style cast
    float f1 = 10.21f;

    /* If i want to do casting we will use static cast instead of c stype cast
    use case : enum to int in different class or any premitive data to another */
    int n1 = static_cast<int>(f1);
    std::cout << n1 << '\n';

    // Type 2 : when parent child runtime polymorphism is in picture
    // a. converting reference
    // b. converting pointer

    //downcasting using reference (2a)
    Parent* ptr1 = new Child();
    Child* ch = dynamic_cast<Child*>(ptr1);
    try{    
    ch->magic();
    }catch(std::bad_cast& e){
        std::cout<<e.what();
    }
    //if we want to use dynamic cast, at least one function in parent class should be virtual
    //if we are using upcasting, then we will have to mark child class distructor and parent class distructor as virtual
    // if we have to use any function in child class which is not in parent class then we will do dynemic cast

    // upcasting using pointer  (2b)
    /* Parent *ptr = new Child();
    ptr->magic(); // ptr type is parent. but function in virtual
    // ptr->ChildDisplay(); will give error because childdisplay is not in parent
    // if conversion fails, we get nullptr
    Child *temp = dynamic_cast<Child *>(ptr);
    if(temp!=nullptr)
    temp->ChildDisplay(); */



}
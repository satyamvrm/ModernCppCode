#include<iostream>

class A{
    int a{0};
    public:
    A() = default;
    virtual void display(){
        std::cout<<"A display\n";
    }
};

class B : public A{
    int b{0};
    public:
    B()=default;
    virtual void display() override{
        std::cout<<"B display\n";
    }
};

class C : public A{
    int c{0};
    public:
    C()=default;
    void display()override{
        std::cout<<"C display\n";
    }
};

class D : public B{
    int d{0};
    public:
    D()=default;
    void display() override{
        std::cout<<"D display\n";
    }
};

int main(){
    A* obj1 = new B();
    A* obj2 = new C();
    A* obj3 = new D();
    obj1->display();
    obj2->display();


    B *temp = dynamic_cast<B*>(obj1);
    temp->display();

    D *temp1 = dynamic_cast<D*>(obj3);


    delete temp1;
    delete obj1;
    delete obj2;




    return 0;

}
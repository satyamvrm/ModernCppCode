#include<iostream>

/* Apointer is an address of something */

/* 
    use case 1: Manke an array
    [  10  |  20  |  30  |  40  ]
    0x11h  0x15h  0x19h  0x23h
*/

void magic(int *arr){
    std::cout<<*arr<<" "<<'\n';
}

void f1(){
    int arr[] = {10,20,30,40};
    magic(arr);
}

/* 
    use case 2 : make an object
    [   10  |   9000.0f |   20  |   7000.0f |   30  |   10000   ]



*/

struct employee
{
    int _id;
    float _salary;
    employee(int id, float sal):_id{id},_salary{sal}{}
    ~employee(){}
};

void magic(employee *arr){
    std::cout<<arr[0]._id<<" "<<arr[0]._salary<<'\n';
    std::cout<<arr[1]._id<<" "<<arr[1]._salary<<'\n';
}

void f2(){
    employee e1(1,10000);
    employee e2(2,12000);
    employee arr[2] = {e1,e2};
    magic(arr);
}

void magic(employee* *arr){
    std::cout<<arr[0]->_id<<" "<<arr[0]->_salary<<'\n';
    std::cout<<arr[1]->_id<<" "<<arr[1]->_salary<<'\n';
}

void f3(){
    employee* e1 = new employee(1,20000);
    employee* e2 = new employee(2,12121);
    employee* arr[2] = {e1,e2};
    magic(arr);
}

int main(){
    f1();
    f2();
    f3();
    return 0;
}
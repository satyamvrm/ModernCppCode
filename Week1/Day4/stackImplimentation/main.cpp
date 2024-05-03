#include<iostream>
#include "Stack.h"

int main(){
    std::cout<<"Program Starts"<<std::endl;
    Stack<int> obj;
    try{
    obj.Push(1);
    std::cout<<"top after push 1 : "<<obj.Peek()<<'\n';
    obj.Push(2);
    std::cout<<"top after push 2 : "<<obj.Peek()<<'\n';
    obj.Push(3);
    std::cout<<"top after push 3 : "<<obj.Peek()<<'\n';
    obj.Pop();
    std::cout<<"Peek after pop : "<<obj.Peek()<<'\n';
    obj.Pop();
    std::cout<<"Peek after pop : "<<obj.Peek()<<'\n';
    obj.PushEven(4,5);
    std::cout<<"Again push : "<<obj.Peek()<<'\n';
    }catch(StackEmptyException& ex){
        std::cout<<ex.what();
    }
}

/*
    throw StackEmptyException("Data is empty"); //statement
    |
    |
    throw <expression> //2 parts of the statement
    |
    |
    throw Constructor call i.e. function call;
    throw [     _msg = " Data is Empty "     ]
           <-------------NO NAME------------>
    throw rvalue of type 
*/
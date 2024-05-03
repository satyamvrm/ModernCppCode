#include<iostream>
#include<list>

//lvalue refreneces
void magic(std::list<int>& data){

}

//rvalue refreneces

/*
    1. weired magic functrion can only be called as a rvalue 
        - it means the user will never be able to copies of the data.
        One in caller(Main) function and one in callee(weiredMagic)
    2. 
*/
void weiredMagic(std::list<int>&& data){
    std::cout<<data.size()<<"\n";

}

int main(){
    std::list<int> l1 {1,2,3,4,5};
    magic(l1); //call by lvalue refrenece
    weiredMagic(std::list<int> {1,2,3,4,5});
}
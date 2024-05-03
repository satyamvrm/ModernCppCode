#include<iostream>
#include<functional>

void magic(std::function<void(int)> fn){
fn(10);
}
int main(){
auto f1 = [](int number){std::cout<<number*10;};
f1(10);
magic([](int num){std::cout<<num*10;});
}

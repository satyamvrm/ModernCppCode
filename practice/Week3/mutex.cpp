#include<iostream>
#include<thread>
#include<mutex>

/*
    Two or more tring to chage the data at same time
    If there is rase condition we have to protect it and thr protected section is cretical section
*/

int amount {10000};
std::mutex mt;
void addMoney(){
    // for(int i=0;i<100;i++)
    // mt.unlock();
    mt.unlock();
    ++amount;
}

void deductMoney(){
    // for(int i=0;i<100;i++)
    --amount;
    mt.lock();
    // mt.lock();
}

int main(){
    std::thread t1(&addMoney);
    std::thread t2(&deductMoney);

    t1.join();
    t2.join();

    std::cout<<"Amount :- "<<amount<<'\n';
}
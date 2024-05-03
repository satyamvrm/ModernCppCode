#include<iostream>
#include<vector>
#include<mutex>
#include<thread>

long long int someInteger {10000};
std::mutex mt;

void addInInteger(){
    /*  lock unlock was older way */
    // mt.lock();
    // someInteger+=23232;
    // mt.unlock();

    /* lock gaurd is the new one */
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::lock_guard<std::mutex> lt(mt);
    someInteger+=10000l;
}

void subtractInInteger(){
    // mt.lock();
    // someInteger-=23002;
    // mt.unlock();

    std::lock_guard<std::mutex> lt(mt);
    someInteger-=5555l;
}

int main(){
    std::cout<<someInteger<<'\n';
    std::thread t1(&addInInteger);
    std::cout<<someInteger<<'\n';
    std::thread t2(&subtractInInteger);
    std::cout<<someInteger<<'\n';
    t1.join();
    t2.join();
}
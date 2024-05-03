#include<iostream>
#include<thread>
#include<mutex>

std::mutex mt;
int buffer = 0;

void task(const char* threadNumber, int loopFor){
std::unique_lock<std::mutex> lock(mt);
for(int i=0; i<loopFor; i++){
buffer++;
std::cout<<threadNumber << buffer << std::endl;
}
}
int main(){
std::thread t1(task,"t1-",5);
std::thread t2(task,"t2-", 5);
t1.join();
t2.join();
}

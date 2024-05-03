/* 
    Producer Consumer Problem
    2 workers in your program
        1 may produce "something"
        the other will "consume it" (process the produced item)
*/
/*  
    2 threads (2 workers)
        - main thread (producer) : take input and "make value avaliable" 
        - operation(t1)[consumer] : Once a signal is recived from main to indicate "input received", calculate the square
            a. progamer caluculate how many workers are requested and triggered them at a time [thread pooling]
            b. t1 may want to do someother work even before data input is recived 
*/
/*
    process/thread : concrete difference or abstract
*/

#include<iostream>
#include<thread>
#include<condition_variable>

int n {0};
std::mutex mt;
std::condition_variable cv;
bool flag = 0;

void Square(){
    int* ans = (int*) malloc(4);
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul,[&](){return flag;});
    *ans = n*n;
    std::cout<<"Square of "<<n<<" is "<<*ans<<'\n';
    free(ans);
}

void takeInput(){
    std::lock_guard<std::mutex> lg(mt);
    std::cin>>n;
}

int main(){
    std::thread t1(&Square);
    takeInput();
    flag = 1;
    cv.notify_one();

    if(t1.joinable()) t1.join();

}
#include<iostream>
#include<thread>

int main(){
    std::cout<<"Main Started"<<'\n';
    std::thread t1(
        [](int n){
            for(int i=0;i<n;i++){
                std::cout<<i<<" ";
            }
        },5
    );
    // if(t1.joinable()) t1.join();
    if(t1.joinable()) t1.detach(); //to detach the thread with main thread without getting error
    std::cout<<"\nMain Ended"<<'\n';
}
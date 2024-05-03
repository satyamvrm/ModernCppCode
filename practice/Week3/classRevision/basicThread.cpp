#include<iostream>
#include<thread>
#include<vector>
#include<functional>

void Square(std::vector<int>& data){
    for(int i=0;i<5;i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<data[i]*data[i]<<'\n';
    }
}

void Cube(std::vector<int>& data){
    for(int i=0;i<5;i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<data[i]*data[i]*data[i]<<'\n';
    }
}

int main(){
    std::vector<int> data {1,2,3,4,5};
    /* This is sequenceal way */
    // Square(data);
    // Cube(data);
    /* Parallel way */
    std::thread t1(&Square,std::ref(data));
    std::thread t2(&Cube,std::ref(data));

    // t1.join();
    // t2.join();
}
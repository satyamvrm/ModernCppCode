#include<iostream>
#include<future>

int square(std::future<int> &ft){
    // int *ans = new int(4);
    int n = ft.get();
    return n*n;
}

int main(){
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();

    std::future<int> result =  std::async(square,std::ref(ft));

    int val=0;
    std::cin>>val;
    pr.set_value(val);
    result.wait();
    std::cout<<result.get()<<'\n';
}
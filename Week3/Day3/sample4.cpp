/* 
    Objective : 
    Design a consumer for:
        - making allocation on heap for 10 interger.
        - save square of all 10 integer in heap
        - claculate sum of first N natural number, where N is accept in the function and return the value.

    Producer thread for:
        - Launching a consumer Accepting N and passing to consumer
*/

#include<iostream>
#include<future>

int Consumer(std::future<int>& ft){
    int* ptr = (int*)malloc(40);
    auto f1 = [](int num){
        return num*num;
    };
    for(int i=1;i<=10;i++){
        ptr[i-1] = f1(i);
    }

    for(int i=1;i<=10;i++) std::cout<<ptr[i-1]<<'\n';
    int n=ft.get();
    return ((n*(n+1))/2);
}


int main(){
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();

    std::future<int> result = std::async(&Consumer, std::ref(ft));

    int val{0};
    std::cin>>val;
    pr.set_value(val);

    result.wait();
    std::cout<<"\nThe sum of first N natural number :- "<<result.get()<<'\n';

}
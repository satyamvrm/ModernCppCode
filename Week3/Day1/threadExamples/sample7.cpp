/*
    create an array of 3 threads
        - thread 1 should calculate square of each number in the array and store in a result array (position 1-5)
        - thread 2 should calculate cube of each number in the array and store in the result array
        - thread 3 should calculate factorial of each number in the array and store a result

*/

#include <iostream>
#include <array>
#include <thread>
#include <mutex>
#include <functional>
std::mutex mt;

using FnType = std::function<void()>;
using FnContainer = std::array<FnType, 3>;
using InputDataContainer = std::array<int, 5>;
using ResultDataContainer = std::array<int, 15>;
using ThreadArray = std::array<std::thread, 3>;

void StoreFunctionInContainer(FnContainer &fns, InputDataContainer &data, ResultDataContainer &result)
{
    fns[0] = [&]()
    {
        for (int i = 0; i < 5; i++)
        {
            std::lock_guard<std::mutex> lk(mt);
            result[i] = data[i] * data[i];
        }
    };
    fns[1] = [&]()
    {
        for (int i = 0; i < 5; i++)
        {
            std::lock_guard<std::mutex> lk(mt);
            result[i + 5] = data[i] * data[i] * data[i];
        }
    };
    fns[2] = [&]()
    {
        int n{1};
        for (int i = 0; i < 5; i++)
        {
            for(int j=data[i];j>0;j--) n*=j;
            std::lock_guard<std::mutex> lk(mt);
            // result[i + 10] = data[i] * data[i] * data[i] * data[i];
            result[i+10] = n;
        }
    };

}

void MapFunctionToThread(FnContainer &fns, ThreadArray &thArr)
{
    for (int i = 0; i < thArr.size(); i++)
    {
        thArr[i] = std::thread(fns[i]);
    }
}

void joinAllThreads(ThreadArray& arr){
    for (std::thread &a : arr)
    {
            if (a.joinable())
                a.join();
    }
}

int main()
{
    InputDataContainer data{1, 2, 3, 4, 5};
    std::array<int, 15> result;
    FnContainer fns;
    ThreadArray thArr;
    StoreFunctionInContainer(fns,data,result);
    MapFunctionToThread(fns,thArr);
    joinAllThreads(thArr);
    for (auto d : result)
    {
            std::cout << d << "\t";
    }
    std::cout << '\n';
    }
#include "EmptyContainerException.h"
#include <iostream>
#include <array>
#include <vector>
#include <thread>
#include <optional>

void CreateData(std::vector<int> &data)
{
    int i = 1;
    data.push_back(i++);
    data.push_back(i++);
    data.push_back(i++);
    data.push_back(i++);
}

void showData(std::vector<int> &data)
{
    if(data.empty()){
        throw EmptyContainerException("Khali baa", std::future_errc::no_state);
    }
    for (int i : data)
    {
        std::cout << i << " ";
    }
}

std::optional<std::vector<int>> Lelo(std::vector<int> & data)
{
    std::vector<int> res;
    if(res.empty()){
        return std::nullopt;
    }
    return res;
}

int main()
{
    std::vector<int> data;
    std::future<void> ans = std::async(CreateData, std::ref(data));
    ans.wait();

    try
    {
        std::future<void> ans2 = std::async(showData, std::ref(data));
        ans2.get();
        std::future<std::optional<std::vector<int>>> ans3 = std::async(Lelo, std::ref(data));
        if(ans3.get().has_value()){
            std::cout<<"Nhai lenge";
        }else{
            std::cout<<"Le lenge";
        }
    }
    catch(EmptyContainerException& ex)
    {
        std::cout<<ex.what();
    }
}
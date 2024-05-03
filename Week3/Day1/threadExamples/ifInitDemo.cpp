#include<iostream>
#include<vector>
#include<optional>

std::optional<std::vector<int>> FindOdd(std::vector<int>& data){
    std::vector<int> result;
    for(int i=0;i<data.size();i++){
        if(data[i]%2 != 0) result.push_back(data[i]);
    }
    if(result.empty()) return std::nullopt;
    return result;
}

int main(){
    std::vector<int> data{2,2,4,4};
    std::optional<std::vector<int>> result = FindOdd(data);
    if(result.has_value()){
        std::cout<<result.size()<<'\n';
    }

}
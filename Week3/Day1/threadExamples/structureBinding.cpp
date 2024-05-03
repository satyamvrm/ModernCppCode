#include<iostream>
#include<array>
#include<unordered_map>

int main(){
    std::unordered_map<int,std::string> map{
        std::make_pair<int,std::string>(101,"Satyam"),
        std::make_pair<int,std::string>(102,"Verma")
    };

    std::array<int,2> data{1,20000};
    auto [empId, empSalary] = data;
    
    for(auto& [k,v] : map){
        std::cout<<k<<"-->"<<v<<'\n';
    }

}
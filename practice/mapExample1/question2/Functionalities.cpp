#include "Functionalities.h"
#include<algorithm>
#include<numeric>

void createObjects(Container &data)
{
    data.emplace(1,
        std::make_shared<Employee>(
            "e101",
            "Example-1",
            15000.0f,
            std::make_shared<Project>(
                "Honda",
                200000.0f
            )
        )
    );
    data.emplace(2,
        std::make_shared<Employee>(
            "e102",
            "Example-2",
            25000.0f,
            std::make_shared<Project>(
                "Honda",
                200000.0f
            )
        )
    );
    data.emplace(3,
        std::make_shared<Employee>(
            "e103",
            "Example-3",
            75000.0f,
            std::make_shared<Project>(
                "BMW",
                100000.0f
            )
        )
    );
    data.emplace(4,
        std::make_shared<Employee>(
            "e104",
            "Example-4",
            85000.0f,
            std::make_shared<Project>(
                "BMW",
                1200.0f
            )
        )
    );
}

void displayObjects(Container &data)
{
    if(data.empty()) throw EmptyContainerException("Provided List is Empty\n");
    for(auto [k,v] : data){
        std::cout<<k<<" - "<<*v<<'\n';
    }
}

int countBudgetOver5000(Container &data)
{
    if(data.empty()) throw EmptyContainerException("Provided List is Empty\n");
    // int count{0};
    // for(std::shared_ptr<Employee> c : data){
    //     if(c->project()->projectBudget() > 5000) count++;
    // }
    int count = std::count_if(
        data.begin(),
        data.end(),
        [](const std::pair<int,std::shared_ptr<Employee>>& row){
            return row.second->project()->projectBudget() > 5000;
        }
    );
    return count;
}

bool allSalaryAbove10K(Container &data)
{
    if(data.empty()) throw EmptyContainerException("Provided List is Empty\n");
    // for(std::shared_ptr<Employee> c : data){
    //     if(c->salary() < 10000) return false;
    // }
    return std::all_of(
        data.begin(),
        data.end(),
        [](const std::pair<int,std::shared_ptr<Employee>>& row){
            return row.second->salary()>10000;
        }
    );
}

float AverageTaxExemption(Container &data)
{
    if(data.empty()) throw EmptyContainerException("Provided List is Empty\n");
    float amount{0};
    // for(std::shared_ptr<Employee> c : data){
    //     amount+=c->TaxExemptionAmount();
    // }
    // return amount/data.size();
    amount = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float val, const std::pair<int,std::shared_ptr<Employee>>& row){
            return val+row.second->TaxExemptionAmount();
        }
    );
    return amount/data.size();
}

void firstNInstances(Container &data, int n)
{  
    if(data.empty()) throw EmptyContainerException("Provided List is Empty\n");
    int count{n};
    for(auto [k,v] : data){
        if(count==0) return;
        std::cout<<*v<<'\n';
        count--;
    }
}

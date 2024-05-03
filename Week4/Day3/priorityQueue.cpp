#include <iostream>
#include <queue>
#include "Employee.h"

struct lessComparator
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

struct lessEmployeeComparator
{
    bool operator()(const Employee &e1, const Employee &e2)
    {
        return e1.yearOfExperience() < e2.yearOfExperience();
    }
};

template <typename T, typename C>
void displayQueue(std::priority_queue<T, std::vector<T>, C> &pq)
{
    while (!pq.empty())
    {
        std::cout << pq.top() << "\n";
        pq.pop();
    }
}

int main()
{
    std::vector<int> data{1, 2, 43, 432, 123, 43};
    std::priority_queue<int, std::vector<int>, lessComparator> pq(data.begin(), data.end());
    std::cout << "Using Struct comparitor :- \n";
    // while (!pq.empty())
    // {
    //     std::cout << "Popping :- " << pq.top() << '\n';
    //     pq.pop();
    // }
    displayQueue<int, lessComparator>(pq);

    std::vector<Employee> data2;
    data2.push_back(Employee("Example-1", 89000.0f, "e101", "IT", 1));
    data2.push_back(Employee("Example-2", 88000.0f, "e102", "Trainer", 2));
    data2.push_back(Employee("Example-3", 89000.0f, "e101", "IT", 3));
    data2.push_back(Employee("Example-4", 88000.0f, "e102", "Trainer", 4));

    auto comparitor = [](const Employee &e1, const Employee &e2)
    {
        return e1.yearOfExperience() < e2.yearOfExperience();
    };

    std::priority_queue<Employee, std::vector<Employee>, lessEmployeeComparator> pq2(data2.begin(), data2.end());
    std::cout << "\n\nUsing Struct comparitor :- \n";
    while (!pq2.empty())
    {
        std::cout << "Popping :- " << pq2.top() << '\n';
        pq2.pop();
    }

    std::priority_queue<Employee, std::vector<Employee>, decltype(comparitor)> pq3(data2.begin(), data2.end(), comparitor);
    std::cout << "\n\nUsing Lambda comparitor :- \n";
    // while (!pq3.empty())
    // {
    //     std::cout << "Popping :- " << pq3.top() << '\n';
    //     pq3.pop();
    // }
    displayQueue<Employee, decltype(comparitor)>(pq3);
}
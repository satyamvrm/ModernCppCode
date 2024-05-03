#include <iostream>
#include <vector>
#include <memory>
#include <functional>

class Employee
{
private:
    int _id;
    std::string _name;
    float _salary;

public:
    Employee() = delete;
    Employee(const Employee &) = delete;
    Employee(const Employee &&) = delete;
    Employee &operator=(const Employee &) = delete;
    Employee &operator=(const Employee &&) = delete;
    ~Employee() = default;
    Employee(int id, std::string name, float salary) : _id{id}, _name{name}, _salary{salary} {}

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs)
    {
        os << "_id: " << rhs._id
           << " _name: " << rhs._name
           << " _salary: " << rhs._salary;
        return os;
    }

    float operator+(const Employee &rhs)
    {
        return _salary + rhs._salary;
    }

    float operator-(const Employee &rhs)
    {
        return _salary - rhs._salary;
    }

    void operator()()
    {
        std::cout << "Salary : " << _salary << " ";
    }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

public:
    std::string name() const { return _name; }

public:
    int id() const { return _id; }
};

/*
    Objective : take a container of raw pointer to employee and filter and prnt details based on predicate passed
*/

void Adaptor(const std::vector<Employee *> &data, std::function<bool(Employee *)> predicate)
{
    for (Employee *e : data)
    {
        if (predicate(e))
            std::cout << *e << '\n';
    }
}

using EmpPtr = std::shared_ptr<Employee>;

std::vector<EmpPtr> Adaptor2(const std::vector<EmpPtr>&data, std::function<bool(EmpPtr)> predicate)
{
    std::vector<EmpPtr> newData;
    for (EmpPtr e : data)
    {
        if (predicate(e))
            newData.push_back(e);
    }
    return newData;
}


int main()
{
    std::vector<Employee *> data{
        new Employee(101, "ABC", 80000.0f),
        new Employee(102, "PQR", 70000.0f),
        new Employee(103, "XYZ", 60000.0f)
    };

    std::vector<EmpPtr> data2 {
        std::make_shared<Employee>(1001,"XYZ",8000.0f),
        std::make_shared<Employee>(1002,"PQR",8000.0f),
        std::make_shared<Employee>(1003,"ABC",8000.0f)
    };
    
    std::cout << "\n1st Function : \n";
    Adaptor(
        data,
        [](Employee *emp)
        { return emp->salary() > 60000; }
    );

    std::cout << "\n2nd Function : \n";
    Adaptor(
        data,
        [](Employee *emp)
        { return emp->id() == 103; }
    );
    
    std::cout << "\n3rd Function : \n";
    Adaptor(
        data,
        [](Employee *emp)
        { return emp->name() == "PQR"; }
    );
    
    std::cout << "\n4th Function : \n";
    std::vector<EmpPtr> data3 = Adaptor2(
        data2,
        [](EmpPtr emp)
        { return emp.get()->id() == 1001; }
    );

    for(auto c : data3){
        std::cout<<*c<<'\n';
    }


}
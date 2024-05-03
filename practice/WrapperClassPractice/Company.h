#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
class Company
{
private:
    int _id{777};
    std::string _name{"NA"};
public:

    Company()=default;
    ~Company()=default;

    Company(int id, std::string name) : _id{id}, _name{name}{}

    friend std::ostream &operator<<(std::ostream &os, const Company &rhs) {
        os << "_id: " << rhs._id
           << " _name: " << rhs._name;
        return os;
    }


    

};

#endif // EMPLOYEE_H

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
class Employee
{
private:
    std::string _name;
    float _salary;
    std::string _id;
    std::string _designation;
    int _yearOfExperience;

public:
    Employee() = default;
    Employee( Employee &) = default;
    Employee(Employee &&) = default;
    Employee &operator=( Employee &) = default;
    Employee &operator=( Employee &&) = default;
    ~Employee() = default;

    Employee(std::string name, float salary, std::string id, std::string designation, int experience) : _name{name}, _id{id}, _designation{designation}, _salary{salary}, _yearOfExperience{experience} {}

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    std::string designation() const { return _designation; }
    void setDesignation(const std::string &designation) { _designation = designation; }

    int yearOfExperience() const { return _yearOfExperience; }
    void setYearOfExperience(int yearOfExperience) { _yearOfExperience = yearOfExperience; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

};

inline std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_name: " << rhs._name
       << " _salary: " << rhs._salary
       << " _id: " << rhs._id
       << " _designation: " << rhs._designation
       << " _yearOfExperience: " << rhs._yearOfExperience;
    return os;
}

#endif // EMPLOYEE_H

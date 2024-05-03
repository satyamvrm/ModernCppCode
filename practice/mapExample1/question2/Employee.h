#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Project.h"
#include<memory>
#include <ostream>
using ProjectPtr = std::shared_ptr<Project>;
class Employee
{
private:
    std::string _employee_id;
    std::string _employee_name;
    float _salary;
    ProjectPtr _project;
public:
    //default constructor disabled
    Employee()=delete;
    //default copy constructor disabled
    Employee(const Employee&) = delete;
    // default move constructor disabled 
    Employee(const Employee&&) = delete;
    // default assignment operator disabled 
    Employee &operator=(const Employee&) = delete; 
    // default move operator disabled
    Employee &operator=(const Employee&&) = delete; 
    // default distructor enabled 
    ~Employee()=default;

    //parameterized constructors
    Employee(std::string id, std::string name, float salary);
    Employee(std::string id, std::string name, float salary, ProjectPtr project);
    
    //function to calculate tax exemption amount
    float TaxExemptionAmount();

    std::string employeeId() const { return _employee_id; }
    void setEmployeeId(const std::string &employee_id) { _employee_id = employee_id; }

    std::string employeeName() const { return _employee_name; }
    void setEmployeeName(const std::string &employee_name) { _employee_name = employee_name; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

    ProjectPtr project() const { return _project; }
    void setProject(const ProjectPtr &project) { _project = project; }

    // output operator
    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

    
};

#endif // EMPLOYEE_H

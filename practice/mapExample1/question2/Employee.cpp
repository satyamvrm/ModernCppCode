#include "Employee.h"
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "\nEmployee_id: " << rhs._employee_id
       << "\nEmployee_name: " << rhs._employee_name
       << "\nSalary: " << rhs._salary
       << "\nProject: " << *(rhs._project)<<'\n';
    return os;
}

Employee::Employee(std::string id, std::string name, float salary) : _employee_id{id}, _employee_name{name}, _salary{salary}
{
    _project = nullptr;
}

Employee::Employee(std::string id, std::string name, float salary, ProjectPtr project) : Employee(id,name,salary)
{
    _project = project;
}

float Employee::TaxExemptionAmount()
{
    if(salary()<10000000) return salary()*0.05;
    else return salary()*0.1 ;
}

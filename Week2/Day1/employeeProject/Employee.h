#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Project.h"
#include<functional>
#include <ostream>

class Employee
{
private:
    std::string _eName;
    std::string _eID;
    std::reference_wrapper<Project> _eProject;
    float _eSalary;

public:
    Employee() = delete;
    Employee(const Employee &) = delete;
    Employee(const Employee &&) = delete;
    Employee &operator=(const Employee &) = delete;
    Employee &operator=(const Employee &&) = delete;
    ~Employee() = default;

    Employee(std::string eid, std::string ename, float sal,std::reference_wrapper<Project> pr);

    std::string eName() const { return _eName; }
    void setEName(const std::string &eName) { _eName = eName; }

    std::string eID() const { return _eID; }
    void setEID(const std::string &eID) { _eID = eID; }

    std::reference_wrapper<Project> eProject() const { return _eProject; }
    void setEProject(const std::reference_wrapper<Project> &eProject) { _eProject = eProject; }

    float eSalary() const { return _eSalary; }
    void setESalary(float eSalary) { _eSalary = eSalary; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H

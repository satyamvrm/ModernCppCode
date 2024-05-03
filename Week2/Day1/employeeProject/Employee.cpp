#include "Employee.h"

Employee::Employee(std::string eid, std::string ename, float sal, std::reference_wrapper<Project> pr) : _eID{eid}, _eName{eName}, _eSalary{sal},_eProject{pr}
{}

std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_eName: " << rhs._eName
       << " _eID: " << rhs._eID
       << " _eSalary: " << rhs._eSalary
       << " _eProject: " << rhs._eProject.get();
    return os;
}


/* 
    -----------
    | Project |
    -----------
    0x100H                                  wrapper
    |                           -----------------
    |                           |               |
    |                           |               |
    --------------------------->|      _ptr     |
                                |               |
                                |               |
                                -----------------

*/
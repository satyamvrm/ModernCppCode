#ifndef COMPANY_H
#define COMPANY_H

#include "Company.h"
#include<memory>
#include<functional>
#include <ostream>

class Emplpoyeee
{
private:
    std::string _cname;
    std::reference_wrapper<Company> _cmpny;
    
public:
    Emplpoyeee()=default;
    ~Emplpoyeee()=default;

    Emplpoyeee(std::string name, std::reference_wrapper<Company> emp) : _cname{name}, _cmpny{emp}{}

    std::string cname() const { return _cname; }
    void setCname(const std::string &cname) { _cname = cname; }

    std::reference_wrapper<Company> emp() const { return _cmpny; }
    void setEmp(const std::reference_wrapper<Company> &emp) { _cmpny = emp; }

    friend std::ostream &operator<<(std::ostream &os, const Emplpoyeee &rhs) {
        os << "_cname: " << rhs._cname
           << " _cmpny: " << rhs._cmpny;
        return os;
    }

    
};

#endif // COMPANY_H

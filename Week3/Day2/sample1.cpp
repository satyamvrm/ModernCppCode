/* Tax payers : Employees, BusinessOwners */

#include <variant> //Algebraic data type (ADT)
#include <iostream>
#include <array>

class BussinessOwner
{
private:
    /* data */
    std::string _name;
    std::string _gstNo;
    float _revenue;
    float _expense;

public:
    BussinessOwner(/* args */) = delete;
    ~BussinessOwner() = default;
    BussinessOwner(std::string name, std::string gst, float revenue, float exeence)
        : _name{name}, _gstNo{gst}, _revenue{revenue}, _expense{exeence} {}
    float calculateTax() { return 0.3f * (_revenue - _expense); }

    std::string name() const { return _name; }

    std::string gstNo() const { return _gstNo; }
    void setGstNo(const std::string &gstNo) { _gstNo = gstNo; }

    float revenue() const { return _revenue; }

    float expense() const { return _expense; }
};

class Employee
{
private:
    /* data */
    std::string _name;
    float _salary;

public:
    Employee(/* args */) = delete;
    ~Employee() = default;
    Employee(std::string name, float salary) : _name{name}, _salary{salary} {}

    std::string name() const { return _name; }

    float salary() const { return _salary; }
};

/*
    I want to use std::array as a contianer os varients where each varient is either of tye employee or businessOwner pointer
*/

using Vtype = std::variant<Employee *, BussinessOwner *>;
using Container = std::array<Vtype, 2>;

void commanAction(Container arr)
{
    for (Vtype v : arr)
    {
        std::visit(
            [](auto &&val)
            { std::cout << "Name(common) :- " << val->name() << "\n"; },
            v);
        }
}

/* For each Vtype (variant) called v,
    a. open varient and check if v holds an alterative of type Bussness owner*
    b. if yes, get data from slot 1 of the varient (because slot 1 is for businessOwner)
        Now, save this to a variable and access revenue.
 */

void nonCommonAction(Container arr)
{
    for (Vtype v : arr)
    {
        if (std::holds_alternative<BussinessOwner *>(v))
        {
            BussinessOwner *ow = std::get<1>(v);
            std::cout << "Revenue(for business) :- " << ow->revenue() << '\n';
        }
        else
        {
            Employee *e = std::get<0>(v);
            std::cout << "Salary(for employee) :- " << e->salary() << '\n';
        }
    }
}

int main()
{

    // Varient don't care how user created the object it is more realted to storing it.
    Employee *emp = new Employee("Satyam", 67000.0f);
    BussinessOwner *bOwner = new BussinessOwner("KPIT", "ehdwidjkqh948", 100, 40);

    // variant are same as union and store one of the datatype at a time from different datatypes
    Container arr{emp, bOwner};
    commanAction(arr);
    nonCommonAction(arr);
}

/*
    Employee       BusnessOwner                            Employee      BusnessOwner
    [ 0x100H       |\\\\\\\\\\\ ]                       [  \\\\\\\\\\ |    0x3829H     ]
    |-------------------------------------arr------------------------------------------|

    Scenario 1 : I want to execute a function that is present in all types of the variant
                e.g. : getter for name.

    Scenario 2 : I want to call a function which only exist in some but not all class.
                e.g. : revenue is in busniess owner but not in employee.



*/
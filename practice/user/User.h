#ifndef USER_H
#define USER_H


#include<iostream>

class User
{
private:
    std::string _name;
    int _age;
    float _income;

public:
    //default constructor disabled
    User()=default;
    //default copy constructor disabled
    User(const User&) = default;
    // default move constructor disabled 
    User(const User&&) = delete;
    // default assignment operator disabled 
    User &operator=(const User&) = default; 
    // default move operator disabled
    User &operator=(const User&&) = delete; 
    // default distructor enabled 
    ~User()=default;

    User(std::string name, int age, float income);

    float operator+(const User& rhs);

    float income() const { return _income; }
    void setIncome(float income) { _income = income; }

    int age() const { return _age; }
    void setAge(int age) { _age = age; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }
    
    friend std::ostream &operator<<(std::ostream &os, const User &rhs);

    
};

#endif // USER_H

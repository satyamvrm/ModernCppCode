#ifndef PROJECT_H
#define PROJECT_H
#include<iostream>
class Project
{
private:
    std::string _project_name;
    float _project_budget;
    
public:
    //default constructor disabled
    Project()=delete;
    //default copy constructor disabled
    Project(const Project&) = delete;
    // default move constructor disabled 
    Project(const Project&&) = delete;
    // default assignment operator disabled 
    Project &operator=(const Project&) = delete; 
    // default move operator disabled
    Project &operator=(const Project&&) = delete; 
    // default distructor enabled 
    ~Project()=default;

    //parameterized constructor
    Project(std::string name, float budget);

    std::string projectName() const { return _project_name; }
    void setProjectName(const std::string &project_name) { _project_name = project_name; }

    float projectBudget() const { return _project_budget; }
    void setProjectBudget(float project_budget) { _project_budget = project_budget; }

    //outstream operator overloading
    friend std::ostream &operator<<(std::ostream &os, const Project &rhs);

    
};

#endif // PROJECT_H

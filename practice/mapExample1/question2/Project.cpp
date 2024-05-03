#include "Project.h"
std::ostream &operator<<(std::ostream &os, const Project &rhs) {
    os << "\nProject_name: " << rhs._project_name
       << "\nProject_budget: " << rhs._project_budget;
    return os;
}

Project::Project(std::string name, float budget) : _project_name{name}, _project_budget{budget}
{
}
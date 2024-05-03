#include "Project.h"
std::ostream &operator<<(std::ostream &os, const Project &rhs) {
    os << "_pID: " << rhs._pID
       << " _budget: " << rhs._budget
       << " _teamSize: " << rhs._teamSize;
    return os;
}

Project::Project(std::string id, float budget, unsigned int teamSize)
:_pID{id}, _budget{budget}, _teamSize{teamSize}
{
}
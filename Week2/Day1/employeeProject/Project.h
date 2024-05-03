#ifndef PROJECT_H
#define PROJECT_H
#include<iostream>
class Project
{
private:
    /* data */
    std::string _pID;
    float _budget;
    unsigned int _teamSize;
public:
    Project()=delete;
    Project(const Project&)=delete;
    Project(const Project&&)=delete;
    Project &operator=(const Project&) = delete;
    Project &operator=(const Project&&) = delete;
    ~Project() = default;

    Project(std::string id,float budget, unsigned int teamSize);

    std::string pID() const { return _pID; }
    void setPID(const std::string &pID) { _pID = pID; }

    float budget() const { return _budget; }
    void setBudget(float budget) { _budget = budget; }

    unsigned int teamSize() const { return _teamSize; }
    void setTeamSize(unsigned int teamSize) { _teamSize = teamSize; }

    friend std::ostream &operator<<(std::ostream &os, const Project &rhs);

    
};

#endif // PROJECT_H

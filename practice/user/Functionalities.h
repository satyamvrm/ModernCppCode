#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<functional>
#include<memory>
#include "User.h"
#include<list>

using Container = std::list<std::shared_ptr<User>>;

void createObjects(Container& data);
void displayObjects(Container& data);

extern std::function<int(Container&)> AverageUserIncome;
extern std::function<std::list<std::string>(Container&,int)> giveUserID;
extern std::function<std::shared_ptr<User>(Container& data)> minimumUserAge;


#endif // FUNCTIONALITIES_H

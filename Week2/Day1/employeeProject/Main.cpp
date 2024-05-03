#include "Employee.h"
#include "Functionalities.h"
#include "Project.h"

int main(){
    Employee** emp = new Employee*[3];
    Project** proj = new Project*[2];
    CreateObjects(emp,proj);
}
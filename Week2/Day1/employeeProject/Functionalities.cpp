#include "Functionalities.h"

void CreateObjects(Employee **employes, Project **projects)
{
    projects[0] = new Project("Pr101",66700.0f,10);
    employes[0] = new Employee("emp101","Satyam",80000.0f,*projects[0]);
    employes[1] = new Employee("emp102","Devansh",75000.0f,*projects[0]);
}



/* 
Mandetory:
    1. Identation, naming convention and comments
    2. Multiple files
        -> separate header
        -> implementation
    3. All functionalities working with proper output, proper corner case
    4. Main side client code
Less Relevent:
    1. use of smart pointer {only for week-1}
    2. custom exception {only for week-1,2}
    3. 
*/
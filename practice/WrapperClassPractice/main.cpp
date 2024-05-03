#include "functionalities.h"

int main(){
    EmployeeContainer cData;
    CompanyContainer eData;

    createObjects(cData,eData);

    displayCompanies(cData);
    displayEmployies(eData);

    DeleteEmployeFromEmploye(eData);
    DeleteEmployeFromEmploye(eData);
    deleteEmplyeeFromCompany(cData);
    // deleteEmplyeeFromCompany(cData);
    
    std::cout<<"\n\n";

    displayCompanies(cData);
    displayEmployies(eData);
}
#include"CopyElisionEmployee.h"

Employee Magic(){
    Employee e1("Satyam",787878.0f,"e101","Traniee",1);
    return e1;
}

int main(){
    Employee emp=Magic();
    std::cout<<emp<<'\n';
}
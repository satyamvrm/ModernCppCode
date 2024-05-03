#include<stdio.h>
struct test
{
    /* data */
    int id;
    float salary;
    char* name;
}person;

int main(){
    struct test *p = &person;
    p->id = 101;
    p->name = "Satyam verma";
    p->salary = 20382.0f;
    printf("%02d\t%s\t%0.2f\n",p->id,p->name,p->salary);
}

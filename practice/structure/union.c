#include<stdio.h>

union test
{
    /* data */
    int c;
    char d;
};


int main(){
    union test t;
    t.c = 10;
    printf("%d\n",t.c);
    t.d ='d';
    printf("%c\n",t.d);
    printf("%d\n",t.c);

}
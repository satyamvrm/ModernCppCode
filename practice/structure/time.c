#include<stdio.h>

#define DELAY 128000

struct my_time
{
    /* data */
    int hours;
    int minutes;
    int seconds;
}s;

void display(struct my_time *t){
    printf("%02d:%02d:%02d\n",t->hours,t->minutes,t->seconds);
}

void delay(void){
    long int t;
    
    for(t=1;t<DELAY;t++);

}

void update(struct my_time *t){
    t->seconds++;
    if(t->seconds==60){
        t->seconds=0;
        t->minutes++;
    }
    if(t->minutes==60){
        t->minutes=0;
        t->hours++;
    }
    if(t->hours==24){
        t->hours=0;
        delay();
    }
}


int main(){
    struct my_time *systime = &s;
    systime->hours=0;
    systime->minutes=0;
    systime->seconds=0;
    for(;;){
        update(systime);
        display(systime);
    }
    return 0;
}

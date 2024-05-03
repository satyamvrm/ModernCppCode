#include <stdio.h>

int main()
{
    int x = 7;
    char v='a';
    printf("%d\n", x);
    printf("%d\n", x << 1);
    printf("%d\n", x << 2);
    printf("%d\n", x << 1 << 3);
    printf("%d\n", x >> 1);
    printf("%c\n", ~(~v));

    int p = &x;
    printf("%d",p);
    
}
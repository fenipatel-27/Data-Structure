#include <stdio.h>

void callByvalue (int x)
{
    x = 20;
}

void call By reference (int *x)
{
    *x = 30;
}

int main()
{
    int a = 10, b = 10;

    printf("\n Before call by value : a = %d", a);
    call By value (a);
    printf("\n After call by value : a = %d", a);

    printf("\n Before call by Reference : b = %d", b);
    call by reference (&b);
    printf("\n After call by Reference : b = %d", b);

    return 0;
}
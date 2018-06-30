#include <stdio.h>
#include <stdlib.h>

int a=10;
int main()
{
    increment(a);
    printf("%d\n", a);
    return 0;
}

int increment(int a)
{
    a=a+1;
    return a;
}

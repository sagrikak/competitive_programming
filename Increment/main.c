#include <stdio.h>
#include <stdlib.h>

void Increment(int* a)
{
    a[0]=a[0]+1;
    //printf("%d\n", *x);
}

int main()
{
    int a[4]={1,2,3,4};
    Increment(a);
    printf("%d", *a);
    return 0;
}

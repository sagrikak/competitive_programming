#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, var;
    for(i=0; i<100; i++)
    {
        scanf("%d", &var);
        if(var==42)
            break;
        else
            printf("%d\n", var);
    }
    return 0;
}

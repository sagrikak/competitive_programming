#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, m, test, i, j, l, o;
    scanf("%d", &test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d", &n,&m);
        if(m==0)
            printf("0/1\n");
        else
        {
            l=m*9*n;
            o=l+8*(n-m)*n;
            for(j=2; j<=l; j++)
            {
                while(l%j==0 && o%j==0)
                {
                    l=l/j;
                    o=o/j;
                }
            }
            printf("%d/%d\n", l,o);
        }
    }
    return 0;
}

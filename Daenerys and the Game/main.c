#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int astr, pstr, j, k, c, num, test;
    scanf("%d", &test);
    for(j=1; j<=test; j++)
    {
        c=0;
        pstr=0;
        scanf("%d", &num);
        for(k=1; k<=num; k++)
        {
            scanf("%d", &astr);
            if(astr+pstr<0 && c==0)
            {
                pstr=abs(astr)+pstr;
                c++;
            }
            else
            {
                pstr=astr+pstr;
            }
            if(pstr<0)
            {
                printf("%d\n", k);
                break;
            }
        }
        if(pstr>=0)
        printf("She did it!\n");
    }
    return 0;
}

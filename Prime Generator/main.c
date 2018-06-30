#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long int t, j, n1, n2, i, count, k, l;
    scanf("%ld", &t);
    for(i=0; i<t; i++)
    {
        l=0;
        scanf("%ld%ld", &n1, &n2);
        for(j=n1; j<=n2; )
        {
            count=0;
            for(k=2; k<=(int)sqrt(j); k++)
            {
                if(j%k==0)
                {
                    break;
                }
                else
                {
                    //printf("count=%ld %ld\n", j, k);
                    count++;
                }
            }
            //printf("%ld %ld\n", j, count);
            if(j==2 || j==3 || count==(int)sqrt(j)-1)
            {
                l++;
            }
            if(j%2==0)
                j++;
            else j+=2;
        }
        printf("%ld\n", l);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    int i, j, k, l, m;
    int64_t count=0;
    int t, a, b, c, d;
    scanf("%d", &t);

    for(i=0; i<t; i++)
    {
        count=0;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int x[b-a+1];
        int y[d-c+1];
        k=0;
        for(j=a; j<=b; j++)
        {
            x[k]=j;
            k++;
        }
        l=0;
        for(j=c; j<=d; j++)
        {
            y[l]=j;
            l++;
        }
        for(j=0; j<=(b-a); j++)
        {
            for(m=0; m<=(d-c); m++)
            {
                if(x[j]<y[m])
                    count++;
            }
        }
        printf("%"PRIu64"\n", count);
    }
    return 0;
}

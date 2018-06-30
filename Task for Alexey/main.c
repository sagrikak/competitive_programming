#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int64_t least(int64_t a, int64_t b)
{
    int64_t hcf, lcm, t, first, second;
    first=a;
    second=b;
    while(b!=0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    hcf=a;
    lcm=(first*second)/hcf;
    return lcm;
}

int main()
{
    int T, N, i, j, k;
    int64_t min, lcm;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d", &N);
        int64_t arr[N];
        for(j=0; j<N; j++)
            scanf("%" PRIu64"", &arr[j]);
        min= least(arr[0], arr[1]);
        for(j=0; j<N-1; j++)
        {
            for(k=j+1; k<N; k++)
            {
                lcm = least(arr[j], arr[k]);
                if(lcm<min)
                    min=lcm;
            }
        }
        printf("%" PRIu64"\n", min);
    }
    return 0;
}




#include <stdio.h>
#include <inttypes.h>

int main()
{
    int i, t;
    long long int n,x,d,k;
    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
        scanf("%lld%lld",&n,&d);
        k=n%d;
        long long int f=n/d;
        int64_t b, l;
        if((n/d)%2==0)
        {
            x=k+(n-k)/2;
            b=(n*x-x*x)/d;
            printf("%"PRIu64"\n", b);
        }
    
        else
        {
            b=(k+(f/2)*d)*(f-f/2);
            l=(k+(f/2+1)*d)*(f-f/2-1);
            if (b>l)
             printf("%"PRIu64"\n",b);
            else
                printf("%"PRIu64"\n",l);
        }
    }
}

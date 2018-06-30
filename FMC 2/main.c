#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        long long unsigned int N,K,P;
        long long unsigned int loc;
        scanf("%llu",&N);
        scanf("%llu",&K);
        scanf("%llu",&P);

        loc=(K+P-1)%N;
        if(loc==0)
            loc=N;
        printf("%llu",loc);

        if(P%2)
            printf(" dare\n");
        else
            printf(" truth\n");
    }
    }

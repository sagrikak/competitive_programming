#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,K,a,i,j;
    scanf("%d", &T);
    for(a=0; a<T; a++)
    {
        scanf("%d", &K);
        for(i=1; i<=(K+1)/2; i++)
        {
            for(j=K-K/2+i; j<=K; j++)
                printf("%d ", j);
            for(j=1; j<K-K/2+i; j++)
                printf("%d ", j);
            printf("\n");
        }
        for(i=1; i<=K/2; i++)
        {
            for(j=i+1; j<=K; j++)
                printf("%d ", j);
            for(j=1; j<=i; j++)
                printf("%d ", j);
            printf("\n");
        }
    }
    return 0;
}

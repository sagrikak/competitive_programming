#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int compare(const void * a, const void *b)
{
    return(*(int *)a-*(int *)b);
}
int main()
{
    int t, i, n, j, k;
    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
        scanf("%d", &n);
        int count[n];
        long long int acc[n];
        for(j=0; j<n; j++)
        {
            scanf("%*[\n\t]%lld\n", &acc[j]);
        }
        qsort(acc, n, sizeof(int64_t), compare);
        for(j=0; j<n; j++)
        {
            printf("%lld", acc[j]);
            printf("\n");
        }
    }
    return 0;
}

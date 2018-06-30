#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

int main()
{
    int64_t i, j, c, k=1, m;
    int n;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        k=k*10;
    j=k-37*(n-1);
    m=10*10*10*10*10*10*10*10*10+7;
    c=j%(m);
    printf("%"PRIu64"", c);
    return 0;
}

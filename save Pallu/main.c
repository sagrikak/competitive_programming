#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int64_t fact(int x);
int main()
{
    int i, n;
    int64_t res=0;
    scanf("%d", &n);
    for(i=2; i<=n; i++)
    {
        res=res+fact(n)/fact(n-i);
    }
    printf("%"PRIu64"\n", res);
    return 0;
}

int64_t fact(int x)
{
    int i;
    int64_t fact=1;
    for(i=2; i<=x; i++)
        fact=fact*i;
    return fact;
}

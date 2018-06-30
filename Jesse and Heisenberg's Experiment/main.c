#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int64_t hcf(int64_t first, int64_t second)
{
	int64_t t;
	int64_t a=first;
    int64_t b=second;

    while(b!=0)
    {   t=b;
        b=a%b;
        a=t;
    }

    return a;
}

int64_t fib(int x)
{
	int64_t j=1, a=1, b=1;
	int i;
	for(i=0; i<x-2; i++)
	{
		j=a+b;
		a=b;
		b=j;
		//printf("%d=%"PRIu64" ", j);
	}
	return j;
}

int main()
{
	int t, m, n, i;
	int64_t j;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		scanf("%d%d", &m, &n);
		j=hcf(fib(m), fib(n));
		printf("%"PRIu64"\n", j%1000000007);
	}
	return 0;
}
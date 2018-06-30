#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int main()
{
	int a, b, i, j;
	scanf("%d%d", &a, &b);
	int64_t x=0, k=0, l=0, m, n;
	for(i=1; i<=a; i++)
	{
		k=i*i+b;
		l=i*i+1;
		m=sqrt(k);
		n=sqrt(l);
		x=x+m-n;
		//printf("%d %d\n", k, l);
	}
	//j=sqrt(2);
	printf("%d", x);
}
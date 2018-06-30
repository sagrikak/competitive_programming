#include <stdio.h>
#include <inttypes.h>

int main()
{
	int i, t;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		int64_t u, v;
		double k;
		int x;
		scanf("%"PRIu64"%"PRIu64"%d", &u, &v, &x);
		k=(double)x/((double)u+(double)v);
		printf("%.10lf\n", k);
	}
}
#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int main()
{
	int b, t;
	scanf("%d", &t);
	for(b=0; b<t; b++)
	{
		int n, i, j;
		int64_t k, d, power, size, tpos;
		scanf("%d", &n);
		scanf("%"PRIu64"", &k);
		size=pow(2, n);
		d=k;
		for(i=1; i<n; i++)
		{
			tpos=(d%size);
			if(tpos%2==0)
			{
				tpos/=2;
			}
			else
			{
				tpos=size/2+tpos/2;
			}
			d=(d/size)*size+tpos;
			size/=2;
		}
		printf("%"PRIu64"\n", d);
	}
}
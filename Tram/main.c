#include <stdio.h>

int main()
{
	int in, out, n, i, x=0, max=0;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d%d", &out, &in);
		x=x-out+in;
		if(max<=x)
			max=x;
		//printf("%d\n", x);
	}
	printf("%d", max);
	return 0;
}
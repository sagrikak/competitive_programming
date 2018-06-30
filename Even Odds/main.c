#include <stdio.h>
#include <inttypes.h>

int main()
{
	long long int n, k;
	int x=0;
	scanf("%"PRIu64"%"PRIu64"", &n, &k);
	if(n%2!=0)
		x++;
	if(k<=n/2+x)
	{
		printf("%"PRIu64"", k*2-1);
	}
	else
	{
		printf("%"PRIu64"", (k-n/2-x)*2);
	}
	return 0;
}
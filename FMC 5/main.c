#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n, k;
	int sum=0;
	scanf("%d%d", &k, &n);
	int a[n];
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	for(i=0; i<n; i++)
	{
		sum=a[i]+sum;
		sum=sum-k;
		if(sum<0)
			sum=0;
	}
	printf("%d\n", sum);
	return 0;
}

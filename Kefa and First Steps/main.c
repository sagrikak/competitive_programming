#include <stdio.h>

int main()
{
	int i, n, count=1, z=1;
	scanf("%d", &n);
	int x[n];
	for(i=0; i<n; i++)
		scanf("%d", &x[i]);

	for(i=0; i<n-1; i++)
	{
		if(x[i]<=x[i+1]) 
			count++;
		else count=1;
		if(count>z)
			z=count;
	}
	printf("%d", z);
	return 0;
}
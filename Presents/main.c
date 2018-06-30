#include <stdio.h>

int main()
{
	int n, i;
	scanf("%d", &n);
	int x[n], y[n];
	for(i=0; i<n ; i++)
	{
		scanf("%d", &x[i]);
		y[x[i]-1]=i+1;
	}
	for(i=0; i<n ; i++)
		printf("%d ", y[i]);
	return 0;
}
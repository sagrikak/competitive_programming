#include <stdio.h>

int main()
{
	int n, m, i, diff, j, temp;
	scanf("%d%d", &n, &m);
	int x[m];
	for(i=0; i<m; i++)
		scanf("%d", &x[i]);

	for(i=0; i<m-1; i++)
	{
		for(j=0; j<m-i-1; j++)
		{
			if(x[j]<x[j+1])
			{
				temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
			}
		}
	}

	diff=x[0]-x[n-1];

	for(i=1; i<m-n+1; i++)
	{
		if(diff>x[i]-x[i+n-1])
			diff=x[i]-x[i+n-1];
	}
	printf("%d", diff);
	return 0;
}
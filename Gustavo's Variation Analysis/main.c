#include <stdio.h>

int main()
{
	int t, n, i, j;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		scanf("%d", &n);
		int arr[n];
		int min=1000000000;
		int max=-1000000000;
		for(j=0; j<n; j++)
		{
			scanf("%d", &arr[j]);
			if(arr[j]<min)
				min=arr[j];
			if(arr[j]>max)
				max=arr[j];
		}
		printf("%d\n", max-min);
	}
	return 0;
}
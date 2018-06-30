#include <stdio.h>

int main()
{
	int i, x, k, count=0;
	int arr[50];
	scanf("%d%d", &x, &k);

	for(i=0; i<x; i++)
	{
		scanf("%d", &arr[i]);
	}
	for(i=0; i<x; i++)
	{
		if(arr[i]>=arr[k-1] && arr[i]>0)
			count++;
	}
	printf("%d", count);
	return 0;
}
#include <stdio.h>

int main()
{
	int i, t;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		int n, j;
		scanf("%d", &n);
		int arr[n];
		for(j=0; j<n; j++)
			scanf("%d", &arr[j]);
		int k=0;
		for(j=0; j<n; j++)
			k=k|arr[j];
		printf("%d\n", k);
	}
}

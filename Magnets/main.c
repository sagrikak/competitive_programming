#include <stdio.h>

int main()
{
	int n, i, x=0;
	scanf("%d", &n);
	int arr[n];

	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);

	for(i=0; i<n-1; i++)
	{
		if(arr[i]!=arr[i+1])
			x++;
	}
	printf("%d", x+1);
	return 0;
}
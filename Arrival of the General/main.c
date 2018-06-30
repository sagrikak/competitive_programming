#include <stdio.h>

int main()
{
	int max=0, min=200, i, n, maxi, mini, x;
	scanf("%d", &n);
	int arr[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
		if(arr[i]>max)
		{
			max=arr[i];
			maxi=i;
		}
		if(arr[i]<=min)
		{
			min=arr[i];
			mini=i;
		}
	}

	if(maxi<mini)
		x=maxi+(n-1)-mini;
	else
		x=maxi+(n-1)-mini-1;

	printf("%d", x);
	return 0;
}
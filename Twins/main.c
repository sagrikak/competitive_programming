#include <stdio.h>

int main()
{
	int n, i, j, sum=0, x=0, temp, count=0;
	scanf("%d", &n);
	int arr[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
		sum=sum+arr[i];
	}

	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(arr[j]<arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

	for(i=0; i<n; i++)
	{
		x=arr[i]+x;
		count++;
		if(x>sum-x)
			break;
	}
	printf("%d", count);
	return 0;
}
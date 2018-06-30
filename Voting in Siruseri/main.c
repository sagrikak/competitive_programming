#include <stdio.h>
#include <stdlib.h>

int arr[250000];

int compare(const void * a, const void * b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int n=0, i, x, k=0, count;
	for(i=0; i<5; i++)
	{
		scanf("%d", &x);
		n=n+x;
	}
	
	//printf("%d", n); 
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), compare);

	for(i=0; i<n-1; i++)
	{
		count=1;
		while(arr[i]==arr[i+1])
		{
			count++;
			i++;
		}
		if(count>=3)
		{
			k++;
			//printf("\n%d", arr[i]);
		}
	}

	printf("%d", k);
	return 0;
}
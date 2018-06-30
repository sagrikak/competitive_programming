#include <stdio.h>
#include <inttypes.h>

int main()
{
	int n, i;
	scanf("%d", &n);
	int arr[n];
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	int p, q, r, s, j;
	int64_t x=0;
	
	for(p=0; p<n-1; p++)
	{
		for(q=p; q<n-1; q++)
		{
			for(r=q+1; r<n; r++)
			{
				for(s=r; s<n; s++)
				{
					int min=100000000, max=0;
					//printf("%d %d %d %d\n", p+1, q+1, r+1, s+1);
					for(i=p; i<=q; i++)
					{
						if(arr[i]>max)
							max=arr[i];
					}
					for(i=r; i<=s; i++)
					{
						if(arr[i]<min)
							min=arr[i];
					}
					//printf("%d %d\n", max, min);
					x=x+(max*min);
				}
			}
		}
	}
	printf("%d", x%1000000007);
}
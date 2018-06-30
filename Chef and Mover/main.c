#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int main()
{
	int t, b;
	scanf("%d", &t);
	for(b=0; b<t; b++)
	{
		int64_t sum=0, x=0, avg;
		int n, j, k=1, d, i, l=1;
		scanf("%d%d", &n, &d);
		int64_t arr[n];
		for(i=0; i<n; i++)
		{
			//arr[i]=1000000000+i*i;
			scanf("%"PRIu64"", &arr[i]);
			sum=sum+arr[i];
		}
		//printf("%"PRIu64"\n", sum);
		if(sum%n==0)
		{
			avg=sum/n;
			//printf("%"PRIu64"\n", avg);
			for(i=0; i<n-d; i++)
			{
				l=1;
				j=i+d;
				if(arr[i]<avg)
				{
					while(arr[j]<avg-arr[i])
					{
						j+=d;
						l++;
						if(j>=n)
						{
							l=0; 
							break;
						}
					}
					if(l==0)
						break;
					x=x+l*(avg-arr[i]);
					arr[j]=arr[j]-(avg-arr[i]);
					arr[i]=avg;
				}
				else if(arr[i]>avg)
				{
					x=x+arr[i]-avg;
					arr[j]=arr[j]+arr[i]-avg;
					arr[i]=avg;
				}
			}
			for(i=0; i<n-1; i++)
			{
				if(arr[i]==arr[i+1])
					k++;
			}
			if(k==n)
				printf("%"PRIu64"\n", x);
			else printf("-1\n");
		}
		else printf("-1\n");
	}
}
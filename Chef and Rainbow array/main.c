#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t, i;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		int j, n, k=1, l=1, m=0;
		scanf("%d", &n);
		int arr[n];
		int x[6]={1, 1, 1, 1, 1, 1};
		for(j=0; j<n; j++)
			scanf("%d", &arr[j]);
		if(arr[0]==1)
			k=1;
		for(j=1; j<n; j++)
		{
			if(arr[j]==arr[j-1])
			{
				if(l<7)
					x[k-1]++;
				if(l>7)
					x[k-1]--;
			}
			else if(arr[j]!=arr[j-1])
			{
				if(l>=7)
					k--;
				else k++;
				if(arr[j]==k)
					l++;
				else break;
				if(l>13)
					break;
			}
		}
		for(j=0; j<6; j++)
			if(x[j]==1)
				m++;
		if(l==13 && m==6)
			printf("yes\n");
		else printf("no\n");
	}
}
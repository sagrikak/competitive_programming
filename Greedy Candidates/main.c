#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

int main()
{
	int b, t;
	scanf("%d", &t);
	for(b=0; b<t; b++)
	{
		int n, m, i, j, k=0, l;
		char temp;
		scanf("%d%d", &n, &m);
		int minsal[n], offeredsal[m], maxoffer[m];
		int qual[n][m];
		int64_t totsal=0;
		int placed=0, used[m], currentsal;
		for(i=0; i<n; i++)
			scanf("%d", &minsal[i]);
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &offeredsal[i], &maxoffer[i]);
			used[i]=0;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%c", &temp);
				if(temp==49)
					qual[i][j]=1;
				else if(temp==48)
					qual[i][j]=0;
				else if(temp==10)
					j--;
			}
		}
		for(i=0; i<n; i++)
		{
			currentsal=minsal[i];
			l=-1;
			for(j=0; j<m; j++)
			{
				if(qual[i][j]==1 && offeredsal[j]>=currentsal && maxoffer[j]>0)
				{
					currentsal=offeredsal[j];
					l=j;	
				}
			}
			//printf("l=%d %d\n", l, currentsal);
			if(l>=0)
			{
				used[l]=1;
				totsal+=currentsal;
				placed++;
				maxoffer[l]--;
			}
		}
		for(i=0; i<m; i++)
		{
			if(used[i]==0)
				k++;
		}
		printf("%d %"PRIu64" %d\n", placed, totsal, k);
	}
}
#include <stdio.h>
#include <math.h>
#include <inttypes.h>
 
long int xor(int a, int b)
{
	int at, bt, i, j;
	int64_t x=0, t=1;
	//printf("\n%d %d\n", a, b);
	
	for(i=31; i>=0; i--)
	{
		t=1;
		at = a >> i;
		if(at&1)
			at=1;
		else at=0;
		bt = b >> i;
		if(bt&1)
			bt=1;
		else bt=0;
		for(j=i; j>0; j--)
			t=t*2;
		
		x=x+((at+bt)%2)*t;
	}
	//printf("\n%"PRIu64"", x);
	return x;
}
int arr[10000][20];
 
int64_t maximum(int begr, int endr, int begc, int endc, int64_t max)
{
	int i, j, k=0;
	int64_t temp=0;
	int row[endr-begr+1], col[endc-begc+1];
	for(i=begr; i<=endr; i++)
	{
		row[k]=0;
		for(j=begc; j<=endc; j++)
		{
			row[k]=xor(row[k], arr[i][j]);
			if(row[k]>max)
				max=row[k];
		}
		k++;
	}
	k=0;
	for(j=begc; j<=endc; j++)
	{
		col[k]=0;
		for(i=begr; i<=endr; i++)
		{
			col[k]=xor(col[k], arr[i][j]);
			if(col[k]>max)
				max=col[k];
		}
		k++;
	}
	//printf("%d", k);
	
	for(j=begr; j<endr; j++)
	{
		temp=row[j];
		if(temp>max)
			max=temp;
		
		for(i=j; i<endr-1; i++)
		{
			if(xor(row[i+1], temp) > temp)
			{
				temp=xor(row[i+1], temp);
				if(temp>max)
					max=temp;
				//printf("max=%"PRIu64"", max);
			}
			else break;
		}
	}
 
	for(j=begc; j<endc; j++)
	{
		temp=col[j];
		if(temp>max)
			max=temp;
		
		for(i=j; i<endc-1; i++)
		{
			if(xor(col[i+1], temp) > temp)
			{
				temp=xor(col[i+1], temp);
				if(temp>max)
					max=temp;
				//printf("max=%"PRIu64"", max);
			}
			else break;
		}
	}
	
	return max;
}
 
int main()
{
	int n, m, i, j, k, l, a;
	int64_t max=0;
	scanf("%d%d", &n, &m);
 
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			scanf("%d", &arr[i][j]);
			if(arr[i][j]>max)
				max=arr[i][j];
		}
	}
	max=maximum(0, n, 0, m, max);
	
	printf("%"PRIu64"", max);
	return 0;
}
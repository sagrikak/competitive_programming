#include <stdio.h>

int search(int a[], int i, int p, int q);

int main()
{
	int n, p, q, i, j, temp, count=0;
	int a[200];

	scanf("%d", &n);
	scanf("%d", &p);
	for(i=0; i<p; i++)
		scanf("%d", &a[i]);
	scanf("%d", &q);
	for(i=p; i<p+q; i++)
		scanf("%d", &a[i]);

	for(i=0; i<p+q-1; i++)
	{
		for(j=0; j<p+q-i-1; j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}


	for(i=1; i<=n; i++)
	{
		if(search(a, i, p, q))
			count++;
		else
		{
			printf("Oh, my keyboard!");
			break;
		}
	}
	if(count==n)
		printf("I become the guy.");
	return 0;
}

int search(int a[], int i, int p, int q)
{
	int beg=0, end=p+q-1, mid=(beg+end)/2;
	while(beg<=end)
	{
		if(i>a[mid])
			beg=mid+1;
		else if(i<a[mid])
			end=mid-1;
		else
			return 1;
		mid=(beg+end)/2;
	}
	return 0;
}
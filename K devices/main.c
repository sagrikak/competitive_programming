#include <stdio.h>
#include <math.h>

void quicksort(int a[], int beg, int end)
{
    int pivot, x, i, temp;
    if(beg>=end)
    return;
    
    temp=a[(beg+end)/2];
    a[(beg+end)/2]=a[end];
    a[end]=temp;
    
    pivot=a[end];
    x=beg;
    
    for(i=beg; i<end; i++)
    {
        if(a[i]<=pivot)
        {
            temp=a[x];
            a[x]=a[i];
            a[i]=temp;
            x++;
        }
    }
    temp=a[end];
    a[end]=a[x];
    a[x]=temp;
    quicksort(a, beg, x-1);
    quicksort(a, x+1, end);
}

int main()
{
	int n, k, i;
	scanf("%d%d", &n, &k);
	int x[n], y[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", &x[i]);
	}
	for(i=0; i<n; i++)
	{
		scanf("%d", &y[i]);
	}
	int dist[n];
	for(i=0; i<n; i++)
	{
		dist[i]=ceil(sqrt((float)x[i]*x[i]+(float)y[i]*y[i]));
	}
	quicksort(dist, 0, n-1);
	printf("%d", dist[k-1]);
}
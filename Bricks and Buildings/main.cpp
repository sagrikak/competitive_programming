#include <iostream>
#include <string.h>
using namespace std;

int count[100001];

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

int divide(int arr[], int k, int x)
{
	int beg=0, end=k-1, mid=(beg+end)/2;
	while(beg<=end)
	{
		if(arr[mid]<x)
			beg=mid+1;
		else if(arr[mid]>x)
			end=mid-1;
		else
			return mid;
		mid=(beg+end)/2;
	}
	return beg;
}

int main()
{
	int n;
	cin>>n;
	int k=0;
	int temp;
	int height[n];
	int buil[100001];
	memset(buil, 0, sizeof(buil));
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		if(buil[temp] == 0)
		{
			height[k]=temp;
			k++;
		}
		buil[temp]++;
	}
	quicksort(height, 0, k-1);
	int t;
	cin>>t;
	memset(count, -1, sizeof(count));
	count[0] = 0;
	count[1] = n;
	for(int i=0; i<t; i++)
	{
		int x;
		cin>>x;
		if(count[x] == -1)
		{
			int c=0;
			for(int j=divide(height, k, x); j<k; j++)
			{
				if(height[j] % x == 0)
					c+=buil[height[j]];
			}
			count[x] = c;
		}
		cout<<count[x]<<endl;
	}
}
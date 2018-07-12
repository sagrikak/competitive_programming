#include <stdio.h>
using namespace std;

int search(int k, int arr[], int n)
{
	int beg=0, end=n-1;
	int mid=(beg+end)/2;
	while(beg<=end)
	{
		if(arr[mid]==k)
			return mid;
		else if(arr[mid]>k)
			end=mid-1;
		else beg=mid+1;
		mid=(beg+end)/2;
	}
	return -1;
}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	int arr[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	for(int i=0; i<q; i++)
	{
		int k, x;
		scanf("%d", &k);
		x=search(k, arr, n);
		while(arr[x-1]==k)
			x--;
		printf("%d\n", x);
	}
}
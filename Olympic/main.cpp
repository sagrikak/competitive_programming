#include <iostream>
using namespace std;

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
	int n, k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	quicksort(arr, 0, n-1);
	for(int i=0; i<n; i++)
	{
		int count=1;
		while(arr[i] == arr[i+1] && i<n-1)
		{
			count++;
			i++;
		}
		if(count%k != 0)
		{
			cout<<arr[i];
			break;
		}
	}
}
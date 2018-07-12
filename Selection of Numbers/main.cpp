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
	int k, n;
	cin>>k>>n;
	int a[n];
	long long int fsum=0, lsum=0;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	quicksort(a, 0, n-1);
	for(int i=0; i<k; i++)
	{
		lsum+=a[n-1-i];
		//cout<<a[n-1-i]<<" ";
	}
	cout<<lsum;
}
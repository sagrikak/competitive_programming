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
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int n, sum=0;
		cin>>n;
		int x[n], y[n];
		for(int j=0; j<n; j++)
			cin>>x[j];
		for(int j=0; j<n; j++)
			cin>>y[j];
		quicksort(x, 0, n-1);
		quicksort(y, 0, n-1);
		for(int j=0; j<n; j++)
			sum+=x[j]*y[j];
		cout<<sum<<endl;
	}
}
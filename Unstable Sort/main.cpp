#include <iostream>
using namespace std;

void quicksort2(int a[][2], int beg, int end)
{
    int pivot, x, i, temp;
    if(beg>=end)
    return;
    
    temp=a[(beg+end)/2][0];
    a[(beg+end)/2][0]=a[end][0];
    a[end][0]=temp;

    temp=a[(beg+end)/2][1];
    a[(beg+end)/2][1]=a[end][1];
    a[end][1]=temp;
    
    pivot=a[end][0];
    x=beg;
    
    for(i=beg; i<end; i++)
    {
        if(a[i][0]<=pivot)
        {
            temp=a[x][0];
            a[x][0]=a[i][0];
            a[i][0]=temp;
            temp=a[x][1];
            a[x][1]=a[i][1];
            a[i][1]=temp;
            x++;
        }
    }
    temp=a[end][0];
    a[end][0]=a[x][0];
    a[x][0]=temp;
    temp=a[end][1];
    a[end][1]=a[x][1];
    a[x][1]=temp;
    quicksort2(a, beg, x-1);
    quicksort2(a, x+1, end);
}

void quicksort(int a[][2], int beg, int end)
{
    int pivot, x, i, temp;
    if(beg>=end)
    return;
    
    temp=a[(beg+end)/2][1];
    a[(beg+end)/2][1]=a[end][1];
    a[end][1]=temp;
    
    pivot=a[end][1];
    x=beg;
    
    for(i=beg; i<end; i++)
    {
        if(a[i][1]>=pivot)
        {
            temp=a[x][1];
            a[x][1]=a[i][1];
            a[i][1]=temp;
            x++;
        }
    }
    temp=a[end][1];
    a[end][1]=a[x][1];
    a[x][1]=temp;
    quicksort(a, beg, x-1);
    quicksort(a, x+1, end);
}

int main()
{
	int n;
	cin>>n;
	int arr[n][2];
	int f[100001] = {0};
	for(int i=0; i<n; i++)
	{
		cin>>arr[i][0];
		arr[i][1] = i+1;
		f[arr[i][0]]++;
	}
	quicksort2(arr, 0, n-1);
	for(int i=0; i<n; i++)
	{
		int count=f[arr[i][0]];
		i = i+count-1;
		//cout<<count<<" "<<i<<endl;
		if(count>1)
			quicksort(arr, i-count+1, i);
	}
	for(int i=0; i<n; i++)
	{
		cout<<arr[i][1]<<" ";
	}
}
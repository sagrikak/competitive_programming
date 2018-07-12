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

int search(int x, int arr[], int n)
{
	int beg=0, end=n-1, mid=(beg+end)/2;
	while(beg<=end)
	{
		if(arr[mid]==x)
			return 1;
		else if(arr[mid]>x)
			end=mid-1;
		else
			beg=mid+1;
		mid=(beg+end)/2;
	}
	return 0;
}

int dig(unsigned long long int a, unsigned long long int b)
{
	int ad[19], temp, i=0;
	if(a>b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	while(a>0)
	{
		ad[i]=a%10;
		i++;
		a=a/10;
	}
	quicksort(ad, 0, i-1);
	while(b>0)
	{
		temp=b%10;
		if(search(temp, ad, i))
			return 1;
		b=b/10;
	}
	return 0;
}

int main()
{
	int n;
	cin>>n;
	unsigned long long int arr[n], count=0;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			count+=dig(arr[i], arr[j]);
			//cout<<arr[i]<<' '<<arr[j]<<" count="<<count<<endl;
		}
	}
	cout<<count;
}
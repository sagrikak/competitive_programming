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

int abs(int x)
{
	if(x<0)
		return -x;
	return x;
}

int maximum(int i, int j, int k, int l)
{
	if(i>=j && i>=k && i>=l)
		return i;
	if(j>=i && j>=k && j>=l)
		return j;
	if(k>=j && k>=i && k>=l)
		return k;
	if(l>=j && l>=k && l>=i)
		return l;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int n;
		cin>>n;
		int min[n], max[n];
		for(int j=0; j<n; j++)
		{
			int m;
			cin>>m;
			int x[m];
			min[j]=1000000000;
			max[j]=0;
			for(int k=0; k<m; k++)
			{
				cin>>x[k];
				if(max[j]<x)
					max[j]=x;
				if(min[j]>x)
					min[j]=x;
			}
		}
		long long int ans=0;
		int a, b, c, d;
		for(int j=0; j<n-1; j++)
		{
			a = abs(min[j] - min[j+1]);
			b = abs(min[j] - max[j+1]);
			c = abs(max[j] - min[j+1]);
			d = abs(max[j] - max[j+1]);
			ans += (j+1) * maximum(a, b, c, d);
		}
		cout<<ans<<endl;
	}
}
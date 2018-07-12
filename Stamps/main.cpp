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
        if(a[i]>=pivot)
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
	for(int i=1; i<=t; i++)
	{
		int req, frnds, sum=0, k=0;
		cin>>req>>frnds;
		int arr[frnds];
		for(int j=0; j<frnds; j++)
			cin>>arr[j];
		quicksort(arr, 0, frnds-1);
		while(sum<req && k<frnds) 
		{
			//cout<<arr[k]<<" ";
			sum+=arr[k];
			k++;
		}
		cout<<"Scenario #"<<i<<":"<<endl;
		if(sum>=req)	
			cout<<k<<endl<<"\n";
		else 
			cout<<"impossible"<<endl<<"\n";
	}
}
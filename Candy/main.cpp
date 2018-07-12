#include <iostream>
using namespace std;

int main()
{
	int n=0;
	while(1)
	{
		cin>>n;
		if(n==-1)
			break;
		int arr[n], sum=0, avg, count=0;
		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		if(sum%n==0)
		{
			avg=sum/n;
			for(int i=0; i<n; i++)
			{
				if(arr[i]<avg)
					count+=avg-arr[i];
			}
			cout<<count<<endl;
		}
		else cout<<"-1"<<endl;
	}
}
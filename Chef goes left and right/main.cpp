#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int n, r, upper=1000000000, lower=0, x=0;
		cin>>n>>r;
		int arr[n];
		for(int j=0; j<n; j++)
			cin>>arr[j];
		for(int j=0; j<n; j++)
		{
			if(arr[j]>r && arr[j]<upper)
				upper=arr[j];
			else if(arr[j]<r && arr[j]>lower)
				lower=arr[j];
			if(arr[j]>upper || arr[j]<lower)
			{
				x=1;
				break;
			}
		}
		if(x==1)
			cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}
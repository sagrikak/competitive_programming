#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int n;
		int min=100000, x;
		cin>>n;
		int arr[n];
		for(int j=0; j<n; j++)
		{
			cin>>arr[j];
		}
		for(int j=n-1; j>=0; j--)
		{
			if(arr[j]<=min)
			{
				min=arr[j];
				x=j+1;
			}
		}
		cout<<x<<endl;
	}
}
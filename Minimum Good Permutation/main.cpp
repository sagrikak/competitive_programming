#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int n, temp;
		cin>>n;
		int arr[n];
		for(int j=0; j<n; j++)
		{
			arr[j]=j+1;
		}
		for(int j=0; j<n; j+=2)
		{
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
		if(n%2!=0)
		{
			arr[n-1]=n;
			temp=arr[n-1];
			arr[n-1]=arr[n-2];
			arr[n-2]=temp;
		}
		for(int j=0; j<n; j++)
		{
			cout<<arr[j]<<" ";
		}
		cout<<endl;
	}
}
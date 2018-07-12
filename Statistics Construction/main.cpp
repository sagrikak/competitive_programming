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
			arr[j]=j+1;
		if (n%2==0 && n>2)
		{
			for(int j=3; j<n; j+=2)
			{
				temp=arr[j];
				arr[j]=arr[j-2];
				arr[j-2]=temp;
			}
		}
		else if(n%2!=0 && n>2)
		{
			for(int j=2; j<n; j+=2)
			{
				temp=arr[j];
				arr[j]=arr[j-2];
				arr[j-2]=temp;
			}
		}
		for(int j=0; j<n; j++)
		{
			cout<<arr[j]<<" ";
		}
		cout<<endl;
	}
}
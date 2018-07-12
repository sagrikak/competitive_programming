#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		unsigned long long int n, x;
		cin>>n;
		unsigned long long int sum=0;
		for(int j=0; j<n; j++)
		{
			cin>>x;
			sum=(sum%n+x%n)%n;
		}
		if(sum%n==0)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
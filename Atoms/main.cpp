#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		unsigned long long int n, k, m, count=0;
		cin>>n>>k>>m;
		while(n<=m)
		{
			n*=k;
			count++;
		}
		cout<<count-1<<endl;
	}
}
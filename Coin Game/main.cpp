#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int x;
		cin>>x;
		int a[x];
		for(int j=0; j<x; j++)
		{
			cin>>a[j];
		}
		int count=0;
		for(int j=0; j<x; j++)
		{
			while(a[j] % 2 == 0)
			{
				a[j]/=2;
				count++;
			}
		}
		if(count%2 == 0)
			cout<<"Alan"<<endl;
		else cout<<"Charlie"<<endl;
	}
}
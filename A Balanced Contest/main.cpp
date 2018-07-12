#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int j=0; j<t; j++)
	{
		int n, p;
		cin>>n>>p;
		int cake=0, hard=0;
		int x;
		for(int i=0; i<n; i++)
		{
			cin>>x;
			if(x>=p/2)
				cake++;
			if(x<=p/10)
				hard++;
		}
		if(hard==2 && cake==1)
			cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}
#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int x, y;
		cin>>x>>y;
		if(x==y || y==x-2)
			cout<<(x+y)-(x%2)<<endl;
		else cout<<"No Number"<<endl;
	}
}
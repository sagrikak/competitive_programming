#include <iostream>
using namespace std;

int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		int x=n*(n+1)*(2*n+1)/6;
		cout<<x<<endl;
	}
}
#include <iostream>
#include <inttypes.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int64_t k, x;
		cin>>k;
		x=2+10*(19+25*(k-1));
		cout<<x<<endl;
	}
}#
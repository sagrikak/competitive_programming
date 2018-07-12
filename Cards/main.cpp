#include <iostream>
#include <inttypes.h>
#include <math.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int n;
		int64_t x, k;
		cin>>n;
		x=2*n;
		k=pow(n, 2)-n;
		k=k/2;
		k*=3;
		x=x+k;
		cout<<x%1000007<<endl;
	}
}

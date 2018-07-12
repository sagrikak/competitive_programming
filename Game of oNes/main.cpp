#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int n;
		cin>>n;
		n--;
		unsigned long long int f, s;
		f=pow(2, n);
		s=f+n*pow(2, n-1);
		cout<<f<<" "<<s<<endl;
	}
}
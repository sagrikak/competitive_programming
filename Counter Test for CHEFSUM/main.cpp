#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		unsigned long long int max = 4294967295, x, y;
		y = 100000;
		x = ((max+1) - 2*y)/(n-1);
		x++;
		if(2*y + (n-1)*x)
		{
			y = ((max+1) - (n-1)*x + 1)/2;
		}
		cout<<y<<" ";
		for(int j = 1; j < n; j++)
			cout<<x<<" ";
		cout<<endl;
	}
}
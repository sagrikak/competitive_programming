#include <iostream>
using namespace std;
#define max 1000000007

int main()
{
	int n;
	cin>>n;
	int arr[n];
	long long int pro=1;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		pro=(pro%max * arr[i]%max)%max;
	}
	cout<<pro;
}
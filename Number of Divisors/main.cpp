#include <iostream>
using namespace std;
#define max 1000000007

int main()
{
	int x;
	cin>>x;
	long long int arr[x];
	long long int fact=1, ans=1;
	for(int i=0; i<x; i++)
	{
		cin>>arr[i];
		fact = (fact % max * (arr[i]+1) % max) % max;
	}
	int t = (fact/2)%max; 
	for(int i=0; i<x; i++)
	{
		int y = ((arr[i]%max) * (500000004%max))%max;
		//cout<<t<<" "<<y<<endl;
		if(fact%2 != 0)
			arr[i] = ((arr[i]%max * t)%max + y)  % max;
		else
			arr[i] = ((arr[i]%max) * t) % max;
		ans = ((ans % max) * ((arr[i]+1) % max)) % max;
	}
	/*for(int i=0; i<x; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;*/
	cout<<ans;
}
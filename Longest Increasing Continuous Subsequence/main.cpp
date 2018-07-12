#include <iostream>
#include <string>
using namespace std;

int main()
{
	string arr;
	cin>>arr;
	int count=1;
	int max=0;
	for(int i=3; i<arr.length()-1; i+=2)
	{
		if(arr.at(i) > arr.at(i-2))
			count++;
		else count=1;
		if(count>max)
			max=count;
	}
	cout<<max;
}
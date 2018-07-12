#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int n;
		cin>>n;
		int arr[7] = {0};
		for(int j=0; j<n; j++)
		{
			string s;
			cin>>s;
			if(s == "cakewalk")
				arr[0]++;
			else if(s == "simple")
				arr[1]++;
			else if(s == "easy")
				arr[2]++;
			else if(s == "easy-medium")
				arr[3]++;
			else if(s == "medium")
				arr[4]++;
			else if(s == "medium-hard")
				arr[5]++;
			else arr[6]++;
		}
		if(arr[0] >= 1 && arr[1] >= 1 && arr[2] >= 1 && (arr[3] >= 1 || arr[4] >= 1) && (arr[5] >= 1 || arr[6] >= 1))
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
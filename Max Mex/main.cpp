#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int n, k, x, j;
		cin>>n>>k;
		int count[200001] = {0};
		for(j=0; j<n; j++)
		{
			cin>>x;
			count[x]++;
		}
		j=0;
		while(k>0 && j<=200000)
		{
			if(count[j]==0)
			{
				count[j]++;
				k--;
			}
			j++;
		}
		j=0, x=-1;
		while(x==-1 && j<=200000)
		{
			if(count[j] == 0)
				x=j;
			j++;
		}
		if(x==-1)
			x=j;
		cout<<x<<endl;
	}
}
#include<iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int j=0; j<t; j++)
	{
		int n, r, count=0, a=0, b=0;
		cin>>n>>r;
		char str2[r+1];
		if(r%2==0)
		{
			memset(str2, 'b', r);
			str2[0]='a';
			str2[r-1]='a';
		}
		else
		{
			memset(str2, 'a', r);
			str2[r/2] = 'b';
		}
		for(int i=0; i<r; i++)
		{
			if(str2[i]=='a')
				a++;
			else b++;
		}
		if(a==0 || b==0)
			cout<<"impossible"<<endl;
		else
		{
			for(int i=0; i<n/r; i++)
			{
				for(int k=0; k<r; k++)
					cout<<str2[k];
			}
			cout<<endl;
		}
	}
}
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		char str[100001];
		cin>>str;
		int len=strlen(str);
		long long int x=0;
		for(int j=0; j<len; j++)
		{
			int count=1;
			while(str[j] == str[j+1] && j<len-1)
			{
				count++;
				j++;
			}
			x=x+count*(count-1)/2;
			if(str[j+1] == str[j-count] && count!=len)
					x++;
		}
		cout<<x<<endl;
	}
}
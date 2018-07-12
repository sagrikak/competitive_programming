#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for (int i = 0; i < t; i++)
	{
		string str;
		char left, right;
		cin>>str;
		int len = str.length();
		int a=0, b=0;
		for(int j=0; j<len; j++)
		{
			if(str[j]=='A')
				a++;
			else if(str[j]=='B')
				b++;
			else if(str[j]=='.')
			{
				int count=0;
				left = str[j-1];
				while(str[j]=='.' && j<len)
				{
					count++;
					j++;
				}
				if(left=='A' && str[j]=='A')
					a+=count;
				else if(str[j]=='B' && left=='B')
					b+=count;
				j--;
			}
		}
		cout<<a<<" "<<b<<endl;
	}
}
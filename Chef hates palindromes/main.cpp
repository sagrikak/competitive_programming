#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int n, a, k=3;
		cin>>n>>a;
		if(n<k)
			k=1;
		char str[n+1];
		if(a==1)
		{
			cout<<n<<" ";
			for(int j=0; j<n; j++)
				cout<<"a";
			cout<<endl;
		}
		else if(a==2 && n<=10)
		{
			if(n==3)
			{
				cout<<"2 aab"<<endl;
				continue;
			}
			if(n==4)
			{
				cout<<"2 aabb"<<endl;
				continue;
			}
			if((n-1)/2 > k)
				cout<<(n-1)/2<<" ";
			else cout<<k<<" ";
			memset(str, 'b', n);
			memset(str, 'a', (n+1)/2);
			str[(n-1)/2]='b';
			str[(n+1)/2]='a';
			for(int j=0; j<n; j++)
				cout<<str[j];
			cout<<endl;
		}
		else if(a==2 && n>10)
		{
			cout<<"4 ";
			for(int j=0; j<n/6; j++)
			{
				cout<<"aababb";
			}
			if(n%6==0)
				cout<<endl;
			else if(n%6==1)
				cout<<"a"<<endl;
			else if(n%6==2)
				cout<<"aa"<<endl;
			else if(n%6==3)
				cout<<"aab"<<endl;
			else if(n%6==4)
				cout<<"aaba"<<endl;
			else if(n%6==5)
				cout<<"aabab"<<endl;;
		}
		else
		{
			cout<<"1 ";
			for(int j=0; j<n/3; j++)
				cout<<"abc";
			if(n%3==1)
				cout<<"a"<<endl;
			else if(n%3==2)
				cout<<"ab"<<endl;
			else cout<<endl;
		}
	}
}
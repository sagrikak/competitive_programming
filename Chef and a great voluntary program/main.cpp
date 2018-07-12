#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		char str[100001], str2[1000001], str3[1000001];
		cin>>str;
		int x, y, j, l;
		cin>>x>>y;
		int a=0, b=0, counta=0, countb=0, app=0, ban=0;
		int len = strlen(str);
		for(j=0; j<len; j++)
		{
			if(str[j] == 'a')
				app++;
			else ban++;
		}
		int k=0, kiwi1=0, kiwi2=0;
		a=app;
		b=ban;
		counta=0;
		countb=0;
		while(b>0 || a>0)
		{
			l=a/x;
			if(a%x != 0)
				l++;
			l--;
			if(l>0)
				l=b/l;
			if(l<=0)
				l=1;
			if(l>y)
				l=y;
			while(counta<x && a>0)
			{
				str2[k] = 'a';
				a--;
				k++;
				counta++;
				countb=0;
			}
			while(countb<l && b>0)
			{
				str2[k] = 'b';
				b--;
				k++;
				countb++;
				counta=0;
			}
			while(b>0 && a==0)
			{
				while(countb<y && b>0)
				{
					str2[k]='b';
					k++;
					b--;
					countb++;
				}
				if(countb==y && b>0)
				{
					str2[k] = '*';
					k++;
					kiwi1++;
					countb=0;
				}
			}
			while(a>0 && b==0)
			{
				while(counta<x && a>0)
				{
					str2[k]='a';
					k++;
					a--;
					counta++;
				}
				if(counta==x && a>0)
				{
					str2[k] = '*';
					k++;
					kiwi1++;
					counta=0;
				}
			}
		}
		int k2=0;
		a=app;
		b=ban;
		counta=0;
		countb=0;
		while(b>0 || a>0)
		{
			l=b/y;
			if(b%y != 0)
				l++;
			l--;
			if(l>0)
				l=a/l;
			if(l<=0)
				l=1;
			if(l>x)
				l=x;
			while(countb<y && b>0)
			{
				str3[k2] = 'b';
				b--;
				k2++;
				countb++;
				counta=0;
			}
			while(counta<l && a>0)
			{
				str3[k2] = 'a';
				a--;
				k2++;
				counta++;
				countb=0;
			}
			while(b>0 && a==0)
			{
				while(countb<y && b>0)
				{
					str3[k2]='b';
					k2++;
					b--;
					countb++;
				}
				if(countb==y && b>0)
				{
					str3[k2] = '*';
					k2++;
					kiwi2++;
					countb=0;
				}
			}
			while(a>0 && b==0)
			{
				while(counta<x && a>0)
				{
					str3[k2]='a';
					k2++;
					a--;
					counta++;
				}
				if(counta==x && a>0)
				{
					str3[k2] = '*';
					k2++;
					kiwi2++;
					counta=0;
				}
			}
		}
		
		if(kiwi1<kiwi2)
		{
			for(int j=0; j<k; j++)
				cout<<str2[j];
		}
		else
		{
			for(int j=0; j<k2; j++)
				cout<<str3[j];
		}
		cout<<endl;
	}
}
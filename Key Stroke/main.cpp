#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

string turncaps(string s, int i)
{
	int len=s.length();
	for(int j=i+1; j<len; j++)
	{
		if(s[j]>=65 && s[j]<=90)
			s[j]+=32;
		else if(s[j]>=97 && s[j]<=122)
			s[j]-=32;
	}
	return s;
}

int main()
{
	string str;
	getline(cin, str);
	int len=str.length();
	int max=0;
	char mat[len][len];
	memset(mat, '-', sizeof(mat));
	int m=0, n=0;
	for(int i=0; i<len; i++)
	{
		if(str[i]=='@')
			str=turncaps(str, i);
		else if(str[i]=='#')
		{
			mat[m][n]='#';
			m++;
			n=0;
		}
		else if(str[i]=='/')
		{
			if(n!=0)
			{
				mat[m][n-1]='-';
				n--;
			}
			else
			{
				n=0;
				m--;
				while(mat[m][n]!='-')
					n++;
				mat[m][n-1]='-';
				n--;
			}
		}
		else if(str[i]=='>')
		{
			if(mat[m][n+1]!='-')
				n++;
			else
			{
				m++;
				n=0;
			}
		}
		else if(str[i]=='<')
		{
			if(n!=0)
				n--;
			else
			{
				m--;
				while(1)
				{
					if(mat[m][n]=='-' || mat[m][n]=='#')
						break;
					n++;
				}
			}
		}
		else if(str[i]=='^')
		{
			if(m!=0)
				m--;
		}
		else if(str[i]=='?')
		{
			if(m!=max)
				m++;
			else
			{
				while(mat[m][n+1]!='-')
					n++;
			}
		}
		else
		{
			if(mat[m][n]=='-')
			{
				mat[m][n]=str[i];
				n++;
			}	
			else
			{
				int k=0;
				while(mat[m][k]!='-')
					k++;
				for(int l=k; l>n; l--)
				{
					mat[m][l]=mat[m][l-1];
				}
				mat[m][n]=str[i];
				n++;
				if(str[i]=='#')
				{
					m++;
					n=0;
				}
			}
		}
		if(m>=max)
			max=m;
		
		for(int i=0; i<len; i++)
		{
			for(int j=0; j<len; j++)
					cout<<mat[i][j];
			cout<<endl;
		}
		cout<<m<<" "<<n<<endl;
	}

	for(int i=0; i<len; i++)
	{
		for(int j=0; j<len; j++)
		{
			if(mat[i][j]=='#')
				cout<<"\n";
			else if(mat[i][j]!='-')
				cout<<mat[i][j];
		}
	}
}
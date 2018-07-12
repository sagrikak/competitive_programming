#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void calculate(int q, int a[])
{
	for(int k=0; k<q; k++)
	{
		if(x==1)
		{
			else if(a[j-1]==-1 && a[i-1]!=-1)
			{
				if(a[i-1]==0)
					a[j-1]=1;
				else a[j-1]=0;
			}
			else if(a[i-1]==-1 && a[j-1]!=-1)
			{
				if(a[j-1]==0)
					a[i-1]=1;
				else a[i-1]=0;
			}
			else if(a[i-1]==-1 && a[j-1]==-1)
			{
				a[i-1]=calculate();
				a[j-1]=abs(1-a[i-1]);
			}
		}
		else 
		{
			if(a[j-1]==-1 && a[i-1]!=-1)
			{
				a[j-1]=a[i-1];
			}
			else if(a[i-1]==-1 && a[j-1]!=-1)
			{
				a[i-1]=a[j-1];
			}
			else if(a[i-1]==-1 && a[j-1]==-1)
			{
				a[i-1]=0;
				a[j-1]=0;
			}
		}
	}
	for(int k=0; k<q; k++)
	{
		if(abs(a[qu[k][0]-1] - a[qu[k][1]-1]) != qu[k][2])
		{
			xbool=0;
			break;
		}
	}
}

int main()
{
	int t;
	cin>>t;
	for(int c=0; c<t; c++)
	{
		int n, q;
		xbool=1;
		cin>>n>>q;
		int a[n];
		memset(a, -1, sizeof(a));
		int qu[q][3];
		int i, j, x;
		for(int k=0; k<q; k++)
		{
			cin>>i>>j>>x;
			qu[k][0]=i;
			qu[k][1]=j;
			qu[k][2]=x;
			for(int k=0; k<n; k++)
			{
				cout<<a[k]<<" ";
			}
			cout<<endl;
		}

		

		
		if(xbool==0)
			cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
}
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
using namespace std;
#define max 1000000007

int main()
{
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; i++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int64_t com[m][n];
		for(int j=0; j<m; j++)
		{
			for(int k=0; k<n; k++)
				com[j][k]=0;
		}
		for(int j=0; j<m; j++)
		{
			int c, a, b;
			cin>>c>>a>>b;
			if(c==1)
			{
				if(j==0)
				{
					for(int k=a-1; k<b; k++)
						com[0][k]++;
				}
				else
				{
					for(int k=0; k<n; k++)
					{
						com[j][k]=com[j-1][k];
						if(k>=a-1 && k<=b-1)
							com[j][k]++;
					}
				}
			}
			else
			{
				for(int k=0; k<n; k++)
				{
					com[j][k]=(com[j-1][k] + com[b-1][k])%max;
					if(a>1)
						com[j][k]=(com[j][k] - com[a-2][k])%max;
				}
			}
			/*for(int k=0; k<n; k++)
			{
				printf("%d ", com[j][k]);
			}
			cout<<endl;*/
		}

		for(int j=0; j<n; j++)
		{
			cout<<com[m-1][j]%max<<" ";
		}
		cout<<endl;
	}
}
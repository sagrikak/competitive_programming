#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int mat[1001][1001];
int dij[1001][1001];
int visited[1001];
int marked[1001];

void addedge(int src, int dest, int w)
{
	src--;
	dest--;
	if(src==dest)
		mat[src][src]=0;
	else if(mat[src][dest] == '*')
	{
		mat[src][dest] = w;
		mat[dest][src] = w;
	}
	else if(mat[src][dest] > w)
	{
		mat[src][dest] = w;
		mat[dest][src] = w;
	}
}

int min(int x, int y)
{
	if(x=='*')
		return y;
	if(y=='*')
		return x;
	if(x>y)
		return y;
	if(y>x)
		return x;
}

int add(int x, int y)
{
	if(x=='*' || y=='*')
		return '*';
	else return x+y;
}

int dijkstra(int n, int a, int b)
{
	int i=0, j=0, k, mark=0, x;
	for(k=0; k<n; k++)
	{
		visited[k]=0;
		marked[k]=0;
	}
	if(1)
	{
		marked[i]=a;
		visited[a-1]=1;
		for(j=0; j<n; j++)
		{
			if(visited[j]==1)
				dij[i][j]=0;
			else dij[i][j]='*';
		}
		i++;
		while(visited[b-1]!=1)
		{
			for(j=0; j<n; j++)
			{
				if(visited[j]==1)
					dij[i][j]=dij[i-1][j];
				else
				{
					if(mat[marked[i-1]-1][j]!=0 && mat[marked[i-1]-1][j]!='*')
					{
						dij[i][j]=min(dij[i-1][j], mat[marked[i-1]-1][j]+mark);
					}
					else dij[i][j]=dij[i-1][j];
				}
			}
			mark='*';
			for(j=0; j<n; j++)
			{
				k=0;
				if(visited[j]==0)
				{
					if(min(mark, dij[i][j]) != mark)
					{
						mark=dij[i][j];
						k++;
					}
				}
				if(k>0)
					x=j;
			}
			visited[x]=1;
			marked[i]=x+1;
			i++;
		}
		return dij[i-1][b-1];
	}
}

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		memset(mat, '*', sizeof(mat));
		int n, q, wt, src, dest, ans;
		cin>>n>>q;
		int cnodes[n+1] = {0};
		for(int j=1; j<=n; j++)
		{
			int m;
			cin>>m;
			cnodes[j] = cnodes[j-1] + m;
			for(int k=1; k<=m; k++)
			{
				cin>>wt;
				if(k==m)
					addedge(cnodes[j-1]+k, cnodes[j-1]+((k+1)%m), wt);
				else
					addedge(cnodes[j-1]+k, cnodes[j-1]+k+1, wt);
			}
		}
		for(int j=1; j<=n; j++)
		{
			cin>>src>>dest>>wt;
			if(j==n)
				addedge(cnodes[n-1]+src, cnodes[0]+dest, wt);
			else
				addedge(cnodes[j-1]+src, cnodes[j]+dest, wt);
		}

		for(int j=0; j<cnodes[n]; j++)
		{
			mat[j][j] = 0;
		}

		for(int j=0; j<q; j++)
		{
			int v1, c1, v2, c2;
			cin>>v1>>c1>>v2>>c2;
			src = cnodes[c1-1]+v1;
			dest = cnodes[c2-1]+v2;
			ans = dijkstra(cnodes[n], src, dest);
			cout<<ans<<endl;
		}
	}
}
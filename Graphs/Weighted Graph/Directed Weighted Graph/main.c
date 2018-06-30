#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 50

int mat[max][max];//Adjency matrix
int dij[max][max];//dijkstra
int marked[max];//dijkstra
int visited[max];//dijkstra and backtracking
int dist[max];//bellford
int parent[max];//bellford
int w0[max][max];//floyall
int w1[max][max];//floyall
bool posw=false;//dij for +ve weights and bell for -ve

int checkvertex(int x, int n)
{
	if(x>n)
	{
		printf("Vertex number %d does not exist.\n", x);
		return 0;
	}
	return 1;
}

void read(int n)
{
	int i, j, w;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(i==j)
				mat[i][j]=0;
			else mat[i][j]='*';
		}
	}
	while(1)
	{
		printf("Enter the number of the source vertex, the destination vertex and the weight associated with the respsective edge.\n");
		printf("To end this process, press 0.\n");
		scanf("%d", &i);
		if(i==0)
			break;
		scanf("%d", &j);
		scanf("%d", &w);
		if(w<0)
			posw=false;
		if(checkvertex(i, n) && checkvertex(j, n))
			mat[i-1][j-1]=w;
	}
}

void addv(int n)
{
	int i, j, w;
	for(i=0; i<n; i++)
	{
		if(i==n-1)
			mat[n-1][i]=0;
		else mat[n-1][i]='*';
	}
	for(i=0; i<n; i++)
	{
		if(i==n-1)
			mat[i][n-1]=0;
		else mat [i][n-1]='*';
	}
	while(1)
	{
		printf("Enter the number of the vertex pointing to vertex number %d, followed by the weight associated with edge.\n", n);
		printf("To end this process, press 0.\n");
		scanf("%d", &j);
		if(j==0)
			break;
		scanf("%d", &w);
		if(w<0)
			posw=false;
		if(checkvertex(j, n))
		{
			mat[j-1][n-1]=w;
		}
	}
	while(1)
	{
		printf("Enter the number of the vertex vertex number %d is pointing to, followed by the weight associated with edge.\n", n-1);
		printf("To end this process, press 0.\n");
		scanf("%d", &j);
		if(j==0)
			break;
		scanf("%d", &w);
		if(w<0)
			posw=false;
		if(checkvertex(j, n))
		{
			mat[n-1][j-1]=w;
		}
	}
}

int removev(int n)
{
	int i, j, k;
	printf("Enter the number of the vertex you want to remove.\n");
	scanf("%d", &k);
	if(!checkvertex(k, n))
		return n;
	for(i=k; i<n; i++)
	{
		for(j=0; j<n; j++)
			mat[i-1][j]=mat[i][j];
		for(j=0; j<n; j++)
			mat[j][i-1]=mat[j][i];
	}
	n--;
	return n;
}

void change(int n)
{
	int j, k, y, z, w;
	printf("Enter the number of the vertex you want to apply the changes to.\n");
	scanf("%d", &j);
	if(!checkvertex(j, n))
		return;
	printf("\n\nChoose an option:\n1. Add a connection\n2. Remove a connection\n3. Change weight of an existing connection\n\n");
	scanf("%d", &k);
	switch(k)
	{
		case 1:
		{
			printf("Enter the number of the new vertex you want vertex number %d to point to.\n", j);
			scanf("%d", &y);
			if(checkvertex(y, n))
			{
				if(mat[j-1][y-1]=='*' || mat[j-1][y-1]==0)
				{
					printf("Enter the weight associated with the edge.\n");
					scanf("%d", &w);
					if(w<0)
						posw=false;
					mat[j-1][y-1]=w;
				}
				else printf("The connection you are trying to establish already exists.\n");
			}
			break;
		}
		case 2:
		{
			printf("Enter the number of the vertex that you don't want vertex number %d to point to.\n", j);
			scanf("%d", &y);
			if(checkvertex(y, n))
			{
				if(mat[j-1][y-1]!=0 && mat[j-1][y-1]!='*')
				{
					if(y==j)
						mat[j-1][y-1]=0;
					else mat[j-1][y-1]='*';
				}
				else printf("The connection you are trying to break doesn't exist.\n");
			}
			break;
		}
		case 3:
		{
			printf("Enter the source and the destination vertex representing the edge.\n");
			scanf("%d%d", &y, &z);
			if(checkvertex(y, n) && checkvertex(z, n))
			{
				if(mat[y-1][z-1]!='*' && mat[y-1][z-1]!=0)
				{
					printf("Enter the new weight.\n");
					scanf("%d", &w);
					if(w<0)
						posw=false;
					mat[y-1][z-1]=w;
				}
				else printf("The connection you are trying to alter does not exist.\n");
			}
			break;
		}
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

void backtrack(int n, int a, int b, int i)
{
	int k, x;
	k=dij[i-1][b-1];
	x=b;
	printf("The shortest path is:\n%d", b);
	while(x!=a)
	{
		i--;
		if(k==dij[i-1][x-1])
			k=dij[i-1][x-1];
		else
		{
			x=marked[i-1];
			printf("<-%d", x);
			k=dij[i-1][x-1];
		}
	}
	printf("\n");
}

void dijkstra(int n)
{
	int i=0, j=0, k, a, b, mark=0, x;
	for(k=0; k<n; k++)
	{
		visited[k]=0;
		marked[k]=0;
	}
	printf("Enter the source and the destination vertex.\n");
	scanf("%d%d", &a, &b);
	if(checkvertex(a, n) && checkvertex(b, n))
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
		printf("The shortest distance is %d.\n", dij[i-1][b-1]);
		/*for(j=0; j<i; j++)
		{
			for(k=0; k<n; k++)
				printf("%d ", dij[j][k]);
			printf("\n");
		}*/
		backtrack(n, a, b, i);
	}
}

void bellford(int n)
{
	int u, v, k, a, b, i, x;
	printf("Enter the source and the destination vertex.\n");
	scanf("%d%d", &u, &v);
	if(checkvertex(u, n) && checkvertex(v, n))
	{
		for(i=0; i<n; i++)
		{
			if(i==u-1)
				dist[i]=0;
			else
				dist[i]='*';
			parent[i]=0;
		}
		for(i=0; i<n; i++)
		{
			k=0;
			for(a=0; a<n; a++)
			{
				for(b=0; b<n; b++)
				{
					if(mat[a][b]!='*' && mat[a][b]!=0)
					{
						if(dist[b]!=min(dist[b], dist[a]+mat[a][b]))
						{
							//printf("%d %d %d\n", dist[b], dist[a], mat[a][b]);	
							dist[b]=dist[a]+mat[a][b];
							parent[b]=a+1;
							k++;
						}
					}
				}
			}
			if(i==n-1 && k>0)
			{
				printf("This graph contains negative cycle and hence shortest path cannot be calculated.\n");
				return;
			}
			if(k==0)
				break;
		}
		//for(i=0; i<n; i++)
			//printf("%d/%d ", dist[i], parent[i]);
		x=v;
		while(x!=u)
		{
			if(dist[x-1]=='*')
			{
				printf("The path dose not exist.\n");
				return;
			}
			x=parent[x-1];
		}
		printf("The shortest distance is %d.\n", dist[v-1]);
		x=v;
		printf("The shortest path is:\n%d", v);
		while(x!=u)
		{
			x=parent[x-1];
			printf("<-%d", x);
		}
	}
}

void printw1(int n)
{
	int i, j;
	printf("\nShortest path matrix:\n\n   ");
	for(i=1; i<=n; i++)
		printf("%d  ", i);
	printf("\n\n");
	for(i=0; i<n; i++)
	{
		printf("%d  ", i+1);
		for(j=0; j<n; j++)
		{
			if(w1[i][j]!='*')
			{
				if(w1[i][j]<10 && w1[i][j]>=0)
					printf("%d  ", w1[i][j]);
				else printf("%d ", w1[i][j]);
			}
			else printf("%c  ", w1[i][j]);
		}
		printf("\n");
	}
}

int add(int x, int y)
{
	if(x=='*' || y=='*')
		return '*';
	else return x+y;
}

void floyall(int n)
{
	int i, j, k;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			w0[i][j]=mat[i][j];
	}
	for(k=0; k<n; k++)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				w1[i][j]=min(w0[i][j], add(w0[i][k],w0[k][j]));
			}
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
				w0[i][j]=w1[i][j];
		}
		//printw1(n);
	}
	printw1(n);
}

void printmatrix(int n)
{
	int i, j;
	printf("\nAdjacency matrix:\n\n   ");
	for(i=1; i<=n; i++)
		printf("%d  ", i);
	printf("\n\n");
	for(i=0; i<n; i++)
	{
		printf("%d  ", i+1);
		for(j=0; j<n; j++)
		{
			if(mat[i][j]!='*')
			{
				if(mat[i][j]<10 && mat[i][j]>=0)
					printf("%d  ", mat[i][j]);
				else printf("%d ", mat[i][j]);
			}
			else printf("%c  ", mat[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int x, n;
	while(1)
	{
		printf("\n\nChoose an option:\n");
		printf("1. Create a new graph\n2. Add a vertex\n3. Remove a vertex\n4. Change connections of the graph\n");
		printf("5. Print Graph\n6. Find shortest path\n7. All pair shortest path\n8. Exit\n\n");
		scanf("%d", &x);
		switch(x)
		{
			case 1:
			{
				printf("Enter the number of vertices in the graph.\n");
				scanf("%d", &n);
				read(n);
				break;
			}
			case 2:
			{
				n++;
				addv(n);
				break;
			}
			case 3:
			{
				n=removev(n);
				break;
			}
			case 4:
			{
				change(n);
				break;
			}
			case 5:
			{
				printmatrix(n);
				break;
			}
			case 6:
			{
				if(posw==true)
					dijkstra(n);
				else bellford(n);
				break;
			}
			case 7:
			{
				floyall(n);
				break;
			}
			case 8: exit(0);
			default:	printf("Please enter a valid number!\n");
		}
	}
	return 0;
}
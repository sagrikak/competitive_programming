#include <stdio.h>
#include <stdlib.h>
#define max 50

int arr[max][max];
int mark[max];
int level[max];
int parent[max];
int indegree[max];
int lpath[max];
int l=1;

struct node
{
	int data;
	struct node* link;
};

struct node* head=NULL;
struct node* list[max];

struct node* insertnode(int j, struct node* head)
{
	struct node* new=(struct node*)malloc(sizeof(struct node));
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp=head;
	new->data=j;
	if(head==NULL || j<head->data)
	{
		new->link=head;
		head=new;
	}
	else
	{
		while(temp->link!=NULL)
		{
			if(temp->link->data>=j)
				break;
			temp=temp->link;
		}
		new->link=temp->link;
		temp->link=new;
	}
	return head;
}

int checkvertex(int x, int n)
{
	if(x>n)
	{
		printf("\nVertex number %d does not exist.\n\n", x);
		return 0;
	}
	return 1;
}

void read(int n, int x)
{
	int j, i;
	for(i=x; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			arr[i][j]=0;
			if(x==n-1)
				arr[j][i]=0;
		}
		head=NULL;
		printf("Enter the vertices vertex number %d is pointing to.\nEnter 0 when finished.\n", i+1);
		while(1)
		{
			scanf("%d", &j);
			if(checkvertex(j, n))
			{
				if(j==0)
					break;
				arr[i][j-1]=1;
				head=insertnode(j, head);
			}
		}
		list[i]=head;
		if(x==n-1)
		{
			printf("Enter the vertices pointing to vertex number %d.\nEnter 0 when finished.\n", i+1);
			while(1)
			{
				scanf("%d", &j);
				if(checkvertex(j, n))
				{
					if(j==0)
						break;
					arr[j-1][i]=1;
					list[j-1]=insertnode(i+1, list[j-1]);
				}
			}
		}
	}
}

int removev(int j, int n)
{
	int i, k;
	for(i=j; i<n; i++)
	{
		for(k=0; k<n; k++)
			arr[i-1][k]=arr[i][k];
		for(k=0; k<n; k++)
			arr[k][i-1]=arr[k][i];
		if(list[i]!=NULL)
			list[i-1]=list[i];
		else list[i-1]=NULL;
	}
	n--;
	for(k=0; k<n; k++)
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		struct node* prev=(struct node*)malloc(sizeof(struct node));
		temp=list[k];
		if(temp!=NULL && temp->data==j)
		{
			list[k]=temp->link;
			temp=temp->link;
		}
		while(temp!=NULL)
		{
			if(temp->data==j)
				prev->link=temp->link;
			else if(temp->data>j)
				temp->data=temp->data-1;
			prev=temp;
			temp=temp->link;
		}
	}
	return n;
}

void change(int j, int n)
{
	int k, x;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	printf("If you want to add a connection, press 1.\nIf you want to remove a connection, press 0.\n");
	scanf("%d", &k);
	if(k==1)
	{
		printf("Enter the number of the new vertex you want vertex number %d to point to.\n", j);
		scanf("%d", &x);
		if(checkvertex(x, n))
		{
			if(arr[j-1][k-1]==0)
				arr[j-1][x-1]=1;
			else
			{
				printf("The connection you are trying to establish already exists.\n");
				return;
			}
			list[j-1]=insertnode(x, list[j-1]);
		}
		else return;
	}
	else if(k==0)
	{
		printf("Enter the number of the vertex that you don't want vertex number %d to point to.\n", j);
		scanf("%d", &x);
		if(checkvertex(x, n))
		{
			if(arr[j-1][x-1]==1)
				arr[j-1][x-1]=0;
			else 
			{
				printf("The connection you are trying to break does not exist.\n");
				return;
			}
			temp=list[j-1];
			if(temp->data==x)
			{
				list[j-1]=temp->link;
				return;
			}
			while(temp->link->data<x)
			{
				temp=temp->link;
			}
			temp->link=temp->link->link;
		}
		else return;
	}
	else printf("You entered an invalid number.\n");
}

void printlist(int n)
{
	int i;
	printf("\nAdjacency list:\n\n");
	for(i=0; i<n; i++)
	{
		printf("%d:  ", i+1);
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp=list[i];
		if(list[i]==NULL)
				printf("-");
		while(temp!=NULL)
		{
			printf("%d ", temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}

void printmatrix(int n)
{
	int i, j;
	printf("\nAdjacency matrix:\n\n   ");
	for(i=1; i<=n; i++)
		printf("%d ", i);
	printf("\n\n");
	for(i=0; i<n; i++)
	{
		printf("%d  ", i+1);
		for(j=0; j<n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

struct node* queue=NULL;

void enqueue(int item)
{
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->link=NULL;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp=queue;
	if(temp==NULL)
		queue=new;
	else
	{
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=new;
	}
}

int dequeue()
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp=queue;
	queue=queue->link;
	return temp->data;
}

int BFS(int a, int x)
{
	int k, i=0;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	enqueue(a);
	level[a]=0;
	while(queue!=NULL)
	{
		a=dequeue();
		if(x==1)
			printf("%d ", a+1);
		i++;
		temp=list[a];
		while(temp!=NULL)
		{
			k=temp->data;
			if(level[k-1]==-1)
			{
				enqueue(k-1);
				level[k-1]=level[a]+1;
				parent[k-1]=a;
			}
			temp=temp->link;
		}
	}
	return i;
}

void component(int n, int x)
{
	int j;
	BFS(x, 0);
	for(j=0; j<n; j++)
	{
		if(level[j]==-1)
		{
			l++;
			//printf("%d %d", j, l);
			component(n, j);
		}
	}
}

void DFS(int a, int x)
{
	int k;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp=list[a];
	mark[a]=1;
	
	while(temp!=NULL)
	{
		k=temp->data;
		if(mark[k-1]==0)
		{
			if(x==1)
				printf("%d ", temp->data);
			DFS(k-1, x);
		}
		temp=temp->link;
	}
	return;
}

int cycle(int n)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		mark[i]=0;
		for(j=0; j<n; j++)
		{
			if(arr[i][j]==1)
			{
				DFS(j, 0);
				BFS(j, 0);
				if(mark[i]>0)
				{
					//printf("\n%d %d", i+1, j+1);
					return 1;
				}
			}
		}
	}
	return 0;
}

void topsort(int n, int x)
{
	int i, j, k=0;
	//for(i=0; i<n; i++)
	//	printf("%d ", indegree[i]);
	for(i=0; i<n; i++)
	{
		indegree[i]=0;
		lpath[i]=0;
		for(j=0; j<n; j++)
		{
			indegree[i]+=arr[j][i];
		}
	}
	while(1)
	{
		for(i=0; i<n; i++)
		{
			if(indegree[i]==0)
			{
				if(x==1)
					printf("%d ", i+1);
				indegree[i]=-1;
				k++;
				for(j=0; j<n; j++)
				{
					if(arr[i][j]==1)
					{
						indegree[j]--;
						if(lpath[i]+1 > lpath[j])
							lpath[j]=1+lpath[i];
					}
				}
			}
		}
		if(k==n)
			break;
	}
}

int main()
{
	int x, y, z, n, j, a, b, i;
	while(1)
	{
		printf("\n\nChoose an option:\n");
		printf("1. Create a new graph\n2. Add a Vertex\n3. Remove a Vertex\n4. Change connections of an existing vertex\n5. Print Graph\n");
		printf("6. Traverse Graph\n7. Check Path and Level\n8. Find Shortest Path\n9. Find number of components\n");
		printf("10. Check the graph for cycles\n11. Perform Topological Sort\n12. See Longest Path\n13. Exit\n\n");
		scanf("%d", &x);
		switch(x)
		{
			case 1:
			{
				printf("Enter the number of vertices.\n");
				scanf("%d", &n);
				read(n, 0);
				break;
			}
			case 2:
			{
				n++;
				read(n, n-1);
				break;
			}
			case 3:
			{
				printf("Enter the number of vertex you want to remove.\n");
				scanf("%d", &j);
				if(checkvertex(j, n))
					n=removev(j, n);
				break;
			}
			case 4:
			{
				printf("Enter the number of the vertex whose connections you want to alter.\n");
				scanf("%d", &j);
				if(checkvertex(j, n))
					change(j, n);
				break;
			}
			case 5:
			{
				printmatrix(n);
				printlist(n);
				break;
			}
			case 6:
			{
				printf("Enter a source vertex(the starting vertex).\n");
				scanf("%d", &y);
				if(checkvertex(y, n))
				{
					printf("Breadth First Traversal: ");
					z=BFS(y-1, 1);
					printf("\nDepth First Traversal: %d ", y);
					DFS(y-1, 1);
					printf("\n%d elements can be reached from vertex %d.", z, y);
				}
				break;
			}
			case 7:
			{
				printf("Enter the vertices to check if a path exists between them.\n");
				scanf("%d%d", &a, &b);
				if(checkvertex(a, n) && checkvertex(b, n))
				{
					DFS(a-1, 0);
					BFS(a-1, 0);
					//for(i=0; i<n; i++)
					//	printf("%d ", mark[i]);
					if(mark[b-1]>0)
						printf("Yes, a path exists.\nLevel: %d\n", level[b-1]);
					else printf("No, path does not exist.\n");
				}
				break;
			}
			case 8:
			{
				printf("Enter the vertices to find shortest path.\n");
				scanf("%d%d", &a, &b);
				if(checkvertex(a, n) && checkvertex(b, n))
				{
					BFS(a-1, 0);
					if(level[b-1]>-1)
					{
						printf("Shortest Path from %d to %d is\n", a, b);
						printf("%d", b);
						i=b-1;
						while(i!=a-1)
						{
							i=parent[i];
							printf("<-%d", i+1);
						}
					}
					else printf("The path does not exist.\n");
					printf("\n");
					//for(i=0; i<n; i++)
					//	printf("%d ", parent[i]);
				}
				break;
			}
			case 9:
			{
				l=1;
				component(n, 0);
				printf("\nThe number of componenets in graph is %d.\n", l);
				break;
			}
			case 10:
			{
				if(cycle(n))
					printf("Cycle(s) exist.\n");
				else
					printf("Cycle does not exist.\n");
				break;
			}
			case 11:
			{
				if(cycle(n))
				{
					printf("Sorry! Topological sort can only be performed for Directed Acyclic Graphs and this graph contains cycles.");
				}
				else
				{
					topsort(n, 1);
				}
				printf("\n");
				break;
			}
			case 12:
			{
				if(cycle(n))
				{
					printf("Sorry! This task can only be performed for Directed Acyclic Graphs and this graph contains cycles.");
				}
				else
				{
					topsort(n, 0);
					printf("Vertices  :  ");
					for(i=0; i<n; i++)
						printf("%d ", i+1);
					printf("\n");
					printf("Path Level:  ");
					for(i=0; i<n; i++)
						printf("%d ", lpath[i]);
				}
				printf("\n");
				break;
			}
			case 13: exit(0);
		}
		for(i=0; i<n; i++)
		{
			mark[i]=0;
			level[i]=-1;
		}
	}
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct node
{
	int data;
	node* link;
};

struct node* arr[1000001];
int level[1000001];
struct node* queue=NULL;

node* addnode(int item, node* head)
{
	struct node* newnode = new node;
	newnode->data = item;
	newnode->link = NULL;
	if(head == NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->link=head;
		head=newnode;
	}
	return head;
}

void addedge(int src, int dest, int w)
{
	arr[dest] = addnode(src, arr[dest]);
	arr[src] = addnode(dest, arr[src]);
}

void enqueue(int item)
{
	struct node* newnode = new node;
	newnode->data=item;
	newnode->link=NULL;
	struct node* temp = new node;
	temp=queue;
	if(temp==NULL)
		queue=newnode;
	else
	{
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=newnode;
	}
}

int dequeue()
{
	struct node* temp = new node;
	temp=queue;
	queue=queue->link;
	return temp->data;
}

void findpath(int a)
{
	int k, i=0;
	struct node* temp = new node;
	enqueue(a);
	level[a]=0;
	while(queue!=NULL)
	{
		a=dequeue();
		//cout<<a<<" ";
		temp=arr[a];
		while(temp!=NULL)
		{
			k=temp->data;
			if(level[k]==-1)
			{
				enqueue(k);
				level[k]=level[a]+1;
			}
			temp=temp->link;
		}
	}
}

void printlist(int n)
{
	int i;
	printf("\nAdjacency list:\n\n");
	for(i=1; i<=n; i++)
	{
		printf("%d:  ", i);
		struct node* temp = new node;
		temp=arr[i];
		if(arr[i]==NULL)
				printf("-");
		while(temp!=NULL)
		{
			printf("%d ", temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int n, q, temp, w;
		int src, dest;
		cin>>n>>q;
		int cnodes[n+1] = {0};
		for(int j=1; j<=n; j++)
		{
			int m;
			cin>>m;
			cnodes[j] = cnodes[j-1] + m;
			for(int k=1; k<=m; k++)
			{
				cin>>w;
				if(k==m)
					addedge(cnodes[j-1]+k, cnodes[j-1]+((k+1)%m), w);
				else
					addedge(cnodes[j-1]+k, cnodes[j-1]+k+1, w);
			}
		}
		for(int j=1; j<=n; j++)
		{
			cin>>src>>dest>>w;
			if(j==n)
				addedge(cnodes[n-1]+src, cnodes[0]+dest, w);
			else
				addedge(cnodes[j-1]+src, cnodes[j]+dest, w);
		}

		//printlist(cnodes[n]);

		for(int j=0; j<q; j++)
		{
			int v1, c1, v2, c2;
			cin>>v1>>c1>>v2>>c2;
			src = cnodes[c1-1]+v1;
			dest = cnodes[c2-1]+v2;
			memset(level, -1, sizeof(level));
			findpath(src);
			int ans = level[dest];
			cout<<ans<<endl;
		}
	}
}
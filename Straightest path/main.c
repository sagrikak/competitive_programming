#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node* link;
};

bool level[1000000];
int parent[1000000];

struct node* head=NULL;
struct node* queue=NULL;
struct node* list[1000000];
int n=0;

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

void read(int arr[], int n, int x, int row, int col)
{
	int j, i;
	for(i=x; i<n; i++)
	{
		head=NULL;
		if(arr[i]==1)
		{
			if(arr[i+1]==1 && (i+1)%col!=0)
			{
				j=i+1;
				head=insertnode(j, head);
			}
			if(arr[i-1]==1 && i%col!=0)
			{
				j=i-1;
				head=insertnode(j, head);
			}
			if(arr[i-col]==1 && i-col>=0)
			{
				j=i-col;
				head=insertnode(j, head);
			}
			if(arr[i+col]==1 && i+col<row*col)
			{
				j=i+col;
				head=insertnode(j, head);
			}
			list[i]=head;
		}
	}
}

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

int BFS(int src, int dest, int path[])
{
	int k, l=0, turn=0, b, a=src;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	enqueue(a);
	level[a]=1;
	while(queue!=NULL)
	{
		a=dequeue();
		temp=list[a];
		while(temp!=NULL)
		{
			k=temp->data;
			if(level[k]==0)
			{
				enqueue(k);
				level[k]=1;
				parent[k]=a;
			}
			temp=temp->link;
		}
	}

	if(level[dest]>0)
	{
		path[l]=dest;
		l++;
		b=dest;
		//printf("%d", b);
		while(b!=src)
		{
			b=parent[b];
			path[l]=b;
			//printf("<-%d", b);
			l++;
		}
		//printf("\n");
		for(b=0; b<l-2; b++)
		{
			if(path[b]-path[b+1] != path[b+1]-path[b+2])
				turn++;
			//printf("i=%d j=%d turn=%d\n", i, j, turn);
		}
	}
	else turn=-1;
	return turn;
}

int minturn(int src, int dest, int path[])
{
	int t=BFS(src, dest, path), pos;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp=list[src];
	while(temp!=NULL)
	{
		
	}
}

int main()
{
	int b, c, row, col, l=0, turn=0, i, j;
	scanf("%d%d", &row, &col);
	int arr[row*col], src, dest, path[row*col];
	for(b=0; b<row; b++)
	{
		char str[col+1];
		scanf("%s", &str);
		for(c=0; c<col; c++)
		{
			if(str[c]=='V')
			{
				arr[c+b*col]=1;
				src=c+b*col;
			}
			else if(str[c]=='H')
			{
				arr[c+b*col]=1;
				dest=c+b*col;
			}
			else if(str[c]=='.')
				arr[c+b*col]=1;
			else arr[c+b*col]=0;
		}
	}
	for(b=0; b<row*col; b++)
	{
		level[b]=0;
		n++;
		read(arr, n, n-1, row, col);
	}

	turn=BFS(src, dest, path);
	printf("%d", turn);
	
}
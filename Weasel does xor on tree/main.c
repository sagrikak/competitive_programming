    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include <inttypes.h>
     
    int64_t level[200000];
     
    struct node
    {
    	int64_t data;
    	struct node* link;
    };
     
    struct node* head=NULL;
    struct node* list[200000];
    int64_t subtree[5000][5000];
     
    struct node* insertnode(int64_t j, struct node* head)
    {
    	struct node* new=(struct node*)malloc(sizeof(struct node));
    	struct node* temp=(struct node*)malloc(sizeof(struct node));
    	temp=head;
    	new->data=j;
    	if(head==NULL)
    	{
    		new->link=head;
    		head=new;
    	}
    	else
    	{
            new->link=temp;
            temp=new;
            head=temp;
    	}
    	return head;
    }

    void read(int64_t i, int64_t j)
    {
    	head=list[i];
    	head=insertnode(j, head);
    	list[i]=head;
    }

    void addedge(int64_t a[], int64_t b[], int64_t n)
    {
        int64_t* visited=(int64_t*)calloc(n, sizeof(int64_t));
        int64_t i=0, count=0;
        visited[0]=1;
        while(count<n-1)
        {
            //printf("i=%d a[i]=%d b[i]=%d\n", i, a[i], b[i]);
            if(visited[a[i]] == 1 && visited[b[i]] != 1)
            {
                read(a[i], b[i]);
                visited[b[i]]=1;
                count++;
            }
            else if(visited[b[i]] == 1 && visited[a[i]] != 1)
            {
                read(b[i], a[i]);
                visited[a[i]]=1;
                count++;
            }
            i=(i+1)%(n-1);
        }
    }
     
    void printlist(int64_t n)
    {
    	int64_t i;
    	printf("\nAdjacency list:\n\n");
    	for(i=0; i<n; i++)
    	{
    		printf("%"PRIu64":  ", i);
    		struct node* temp=(struct node*)malloc(sizeof(struct node));
    		temp=list[i];
    		if(list[i]==NULL)
    				printf("-");
    		while(temp!=NULL)
    		{
    			printf("%"PRIu64" ", temp->data);
    			temp=temp->link;
    		}
    		printf("\n");
    	}
    }
     
    struct node* queue=NULL;
     
    void enqueue(int64_t item)
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
     
    int64_t dequeue()
    {
    	struct node* temp=(struct node*)malloc(sizeof(struct node));
    	temp=queue;
    	queue=queue->link;
    	return temp->data;
    }
     
    void BFS(int64_t a, int64_t n)
    {
    	int64_t k, i;
    	for(i=0; i<n; i++)
        {
            level[i]=-1;
        }
    	int64_t x=a;
    	struct node* temp=(struct node*)malloc(sizeof(struct node));
    	enqueue(a);
        //printf("\na=%d ", a);
    	level[a]=0;
        i=0;
    	while(queue!=NULL)
    	{
    		a=dequeue();
            subtree[x][i]=a;
            i++;
            //printf("%d ", a);
    		temp=list[a];
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
     
    int64_t xor(int64_t x[], int64_t n, int64_t arr[])
    {
    	int64_t i, j, k=0, xy=1, l=0;
    	int64_t t[n], y[n];
        for(i=0; i<n; i++)
            y[i]=x[i];
    	for(i=1; ; i++)
    	{
            k=0;
    		for(j=0; j<n; j++)
            {
                t[j]=0;
                l=0;
                while(subtree[j][l] != -1)
                {
                    t[j]=t[j]^x[subtree[j][l]];
                    l++;
                }
            }
    		for(j=0; j<n; j++)
    		{
    			x[j]=t[j];
                if(x[j]==y[j])
                    k++;
    		}
         
           /*printf("i=%"PRIu64" ", i);
            for(j=0; j<n; j++)
                printf("%"PRIu64" ", x[j]);
            printf("\n");*/

            if(k==n)
            {
                xy=i;
                //printf("xy=%d\n", xy);
                break;
            }
            arr[i]=x[0];
    	}
        return xy;
    }
     
    int main()
    {
    	int64_t n, m, i;
    	scanf("%"PRIu64"%"PRIu64"", &n, &m);
        int64_t a[n-1], b[n-1];
    	for(i=0; i<n-1; i++)
    	{
    		scanf("%"PRIu64"%"PRIu64"", &a[i], &b[i]);
    	}
        memset(subtree, -1, sizeof(subtree));
        addedge(a, b, n);
    	int64_t x[n];
    	for(i=0; i<n; i++)
    	{
            scanf("%"PRIu64"", &x[i]);
            BFS(i, n);
        }
        /*for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                print64_tf("%d ", subtree[i][j]);
            print64_tf("\n");
        }*/
        //printlist(n);
        int64_t arr[10000000];
        arr[0]=x[0];
        int64_t xy=xor(x, n, arr);
    	for(i=0; i<m; i++)
    	{
    		int64_t day;
    		scanf("%"PRIu64"", &day);
    		printf("%"PRIu64"\n", arr[(day)%xy]);
    	}
    } 
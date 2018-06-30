    #include <stdio.h>
    #include <inttypes.h>
    #include <stdlib.h>
    #include <stdbool.h>
     
    struct node
    {
        struct node* left;
        int data;
        struct node* right;
    };
    struct node* root=NULL;
     
    void insert(int x)
    {
        struct node* temp=root;
        struct node* new=(struct node*)malloc(sizeof(struct node));
        new->data=x;
        new->left=NULL;
        new->right=NULL;
        if(root==NULL)
        {
            root=new;
            return;
        }
        while(1)
        {
            while(x<=temp->data)
            {
                if(temp->left==NULL)
                {
                    temp->left=new;
                    return;
                }
                else temp=temp->left;
            }
            while(x>temp->data)
            {
                if(temp->right==NULL)
                {
                    temp->right=new;
                    return;
                }
                else temp=temp->right;
            }
        }
    }
     
    struct node* search(int item)
    {
        struct node* temp=root;
        while(temp!=NULL)
        {
            if(item<temp->data)
                temp=temp->left;
            else if(item>temp->data)
                temp=temp->right;
            else if(item==temp->data)
                return temp;
        }
        if(temp==NULL)
            return temp;
    }
     
    struct node* min(struct node* temp)
    {
        while(temp->left!=NULL)
            temp=temp->left;
        return temp;
    }
     
    struct node* delete(struct node* temp, int y)
    {
        if(temp->data>y)
            temp->left=delete(temp->left, y);
        else if(temp->data<y)
            temp->right=delete(temp->right, y);
        else
        {
            if(temp->left==NULL && temp->right==NULL)
            {
                free(temp);
                temp=NULL;
            }
            else if(temp->left==NULL)
                temp=temp->right;
            else if(temp->right==NULL)
                temp=temp->left;
            else
            {
                temp->data=min(temp->right)->data;
                temp->right=delete(temp->right, temp->data);
            }
        }
        return temp;
    }
     
    struct stack
    {
        struct node* stk[500000];
        int top;
    };
     
    struct stack A;
     
    void push(struct node* item)
    {
        A.top=A.top+1;
        A.stk[A.top]=item;
    }
     
    struct node* pop()
    {
        A.top--;
        return A.stk[A.top+1];
    }
     
    int64_t traverse(int f[], int i, int64_t sum)
    {
        struct node* cur=root;
        bool done=0;
        while(!done)
        {
            if(cur!=NULL)
            {
                push(cur);
                cur=cur->left;
            }
            else
            {
                if(A.top>-1)
                {
                    cur=pop();
                    //printf("%d ", cur->data);
                    sum+=((cur->data)/i)*f[cur->data];
                    cur=cur->right;
                }
                else done=1;
            }
        }
        return sum;
    }
     
    int main()
    {
        int n, q, b, l=0, temp;
        A.top=-1;
        scanf("%d%d", &n, &q);
        int arr[n];
        int* freq=(int*)calloc(500001, sizeof(int));
        for(b=0; b<n; b++)
        {
            scanf("%d", &arr[b]);
            if(search(arr[b])==NULL)
                insert(arr[b]);
            freq[arr[b]]++;
        }
        for(b=0; b<q; b++)
        {
            int x;
            scanf("%d", &x);
            if(x==1)
            {
                int i, j;
                scanf("%d%d", &i, &j);
                freq[arr[i-1]]--;
                if(freq[arr[i-1]]==0)
                    delete(root, arr[i-1]);
                if(search(j)==NULL)
                    insert(j);
                freq[j]++;
                arr[i-1]=j;
            }
            else if(x==2)
            {
                int i, j=1;
                int64_t sum=0;
                scanf("%d", &i);
                sum=traverse(freq, i, sum);
                printf("%"PRIu64"\n", sum);
            }
            /*printf("\nArray:\n");
            for(x=0; x<n; x++)
            {
                printf("%d ", arr[x]);
            }
            printf("\nPosition:\n");
            for(x=0; x<l; x++)
            {
                printf("%d ", pos[x]);
            }
            printf("\nFrequency\n");
            for(x=0; x<l; x++)
            {
                printf("%d ", freq[pos[x]]);
            }
            printf("\n\n");*/
        }
     
    }
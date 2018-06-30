

    #include <stdio.h>
    #include <stdlib.h>
    #define max 500000
     
    struct stack
    {
        int stk[max];
        int top;
    };
     
    struct stack A;
     
    void push(int item)
    {
        A.top=A.top+1;
        A.stk[A.top]=item;
    }
     
    int main()
    {
        int n, k, i, j;
        scanf("%d", &n);
        int a[n], item[n];
        for(i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
            if(a[i]==1)
            {
                scanf("%d", &item[i]);
            }
            else if(a[i]==0)
                item[i]=0;
            else if(a[i]==2)
            {
                A.top=-1;
                int count=0;
                scanf("%d", &k);
                scanf("%d", &item[i]);
                for(j=0; j<k; j++)
                {
                    if(a[j]==1)
                    {
                        push(item[j]);
                        if(item[j]<item[i])
                            count++;
                    }
                    else if(a[j]==0)
                    {
                        if(A.stk[A.top]<item[i])
                            count--;
                        A.top--;
                    }
                    else
                        continue;
                }   
                printf("%d\n", count);
            }
        }
        return 0;
    }


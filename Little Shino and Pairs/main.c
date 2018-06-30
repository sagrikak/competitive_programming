    #include <stdio.h>
     
    int p[100000][2];
     
    int search(int a, int b, int k)
    {
        int i;
        for(i=0; i<k; i++)
        {
            if(p[i][0]==a && p[i][1]==b)
                return 0;
        }
        return 1;
    }
     
    int main()
    {
        int n, max1=0, max2=0, i, l, j, k=0;
        scanf("%d", &n);
        int arr[n];
        for(i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
        }
        
        for(l=0; l<n-1; l++)
        {
            max1=0; 
            max2=0;
            for(i=l+1; i<n; i++)
            {   
                for(j=l; j<=i; j++)
                {
                    //printf("%d ", arr[j]);
                    if(arr[j]>max1)
                        max1=arr[j];
                }
                //printf("\n");
                for(j=l; j<=i; j++)
                {
                    if(arr[j]>max2)
                    {
                        if(arr[j]==max1)
                            continue;
                        max2=arr[j];
                    }
                }
                if(search(max1, max2, k))
                {
                    p[k][0]=max1;
                    p[k][1]=max2;
                    k++;
                }
                //printf("max=%d %d", max1, max2);
            }
        }
        //for(i=0; i<k; i++)
            //printf("%d ", p[i]);
        printf("%d", k);
        
        return 0;
    }
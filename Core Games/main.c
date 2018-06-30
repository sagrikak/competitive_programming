#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n, k, c, x, y, count=0;
    scanf("%d%d", &n,&k);
    c=k;
    int ar[n];
    for(i=0; i<n; i++)
    {
        ar[i]=i+1;
    }
    y=k;
    x=ar[k-1];
    for(i=0; i<n; )
    {
        printf("%d ", x);
        y=y+c;
        while(y>n)
            y=y-n;
        if(ar[y-1]==x)
        {
            y=y+1;
            count++;
            while(y>n)
                y=y-n;
        }

        x=ar[y-1];
        //if(count>0)
        //{
           // for(j=k-2; j<n-1; j++)
            //{
              //  ar[j]=ar[j+1];
            //}
            //count=0;
        //}
        //else
        //{
            for(j=k-1; j<n-1; j++)
            {
                ar[j]=ar[j+1];
            }
        //}
        n=n-1;
        if(count>0)
        {
            k=y-1;
            count=0;
        }
        else k=y;
    }
    return 0;
}

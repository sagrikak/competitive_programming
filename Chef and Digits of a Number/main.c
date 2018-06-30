#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,t,count,len,x=0;
    char ar[100005];
    scanf("%d", &t);
    getchar();
    for(i=0; i<t; i++)
    {
        scanf(" %[^\n]s", &ar);
        count=0;
        x=0;
        len=strlen(ar);
        if(len==1)
        {
            printf("Yes\n");
            continue;
        }
        while(x<len-1)
        {
            if(x==0 || x+1==len-1)
            {
                if((int)ar[x]!=(int)ar[x+1])
                {
                    if(x==0)
                    {
                        if((int)ar[x+1]==(int)ar[x+2])
                        count=count+2;
                        else count=count+1;
                    }
                    if(x+1==len-1)
                    {
                        if((int)ar[x]==(int)ar[x-1])
                        count=count+2;
                        else count=count+1;
                    }
                }
            }
            else
            {
                if((int)ar[x]!=(int)ar[x+1])
                    count++;
            }
            x++;
        }
        if(count==2)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

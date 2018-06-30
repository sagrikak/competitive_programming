#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int sum, points=0;
    int test, n, j, i, c, k, o, p, player;
    scanf("%d", &test);
    for(i=0; i<test; i++)
    {
        scanf("%d", &n);
        for(j=0; j<n; j++)
        {
            scanf("%d", &c);
            sum=c;
            int type[c];
            int count[6]={0,0,0,0,0,0};
            for(k=0; k<c; k++)
                scanf("%d", &type[k]);
            for(k=0; k<c; k++)
            {
                if(type[k]==1)
                    count[0]=count[0]+1;
                else if(type[k]==2)
                    count[1]=count[1]+1;
                else if(type[k]==3)
                    count[2]=count[2]+1;
                else if(type[k]==4)
                    count[3]=count[3]+1;
                else if(type[k]==5)
                    count[4]=count[4]+1;
                else if(type[k]==6)
                    count[5]=count[5]+1;
            }
            o=0;
            while(o<3)
            {
                o=0;
                for(k=0; k<6; k++)
                {
                    if(count[k]==0)
                        o++;
                }
                if(o==0)
                    sum=sum+4;
                else if(o==1)
                    sum=sum+2;
                else if(o==2)
                    sum=sum+1;
                for(k=0; k<6; k++)
                {
                    if(count[k]!=0)
                        count[k]=count[k]-1;
                }
            }
            if(sum==points)
                p++;
            else if(sum>points)
            {
                points=sum;
                player=j+1;
            }
        }
        if(p>0)
            printf("tie\n");
        else if(player==1)
            printf("chef\n");
        else printf("%d\n", player);
        points=0; p=0;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c, i, count=0, x, j, y;
    float s, area, r, rs;
    scanf("%f", &rs);
    int tri[500];
    x=0;
    for(a=1; a<10*rs ; a++)
    {
        for(b=a; b<50*rs ; b++)
        {
            for(c=b; c<a+b ; c++)
            {
                s=((float)a+(float)b+(float)c)/2;
                y=s*(s-a)*(s-b)*(s-c);
                area=sqrt(y);

                r=area/s;
                //printf("a=%d\tb=%d\tc=%d\ts=%f\tarea=%f\t%f\n", a,b,c,s,area,r);
                if(r==rs)
                {
                    tri[x]=a; tri[x+1]=b; tri[x+2]=c;
                    count++;
                    x=x+3;
                }
            }
        }
    }
    printf("%d\n", count);
    j=0;
    for(i=0; i<count; i++)
    {
        printf("%d %d %d\n", tri[j], tri[j+1], tri[j+2]);
        j=j+3;
    }
    return 0;
}

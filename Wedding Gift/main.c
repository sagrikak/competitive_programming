#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, i, req, left, gift;
    scanf("%d", &x);
    int pow=1;
    for(i=1; i<16; i++)
    {
        pow=pow*3;
        if(x<pow)
        {
            req=pow;
            break;
        }

    }
    if(req>10000000)
        printf("0\n");
    else
    {
        left=req-x;

        pow=1;
        for(gift=0; gift<=left; )
        {
            gift=gift+pow;
            pow=pow*3;
        }
    printf("%d %d", req, gift-(pow/3));
    }
    return 0;
}

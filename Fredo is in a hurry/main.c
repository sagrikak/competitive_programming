#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    int64_t diff, x, ele, n, time;
    int t, i;
    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
        scanf(" %"PRIu64"", &n);
        time=0;
        ele=n;
        x=0;
        while(ele>=x)
        {
            diff=ele-x;
            if(diff==0)
            {
                time=time+n-ele;
                break;
            }
            else if(diff>x+1)
            {
                x++;
                time=time+x;
                ele=ele-x;
            }
            else if(diff<=x+1)
            {
                time=time+diff;
                ele=ele-diff;
            }
        }

        if(n==1)
           time=1;

        printf("%"PRIu64"\n", time);
    }
    return 0;
}

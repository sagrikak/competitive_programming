#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test, i, n, j, l, p=1, c;
    scanf("%d", &test);

    for(i=1; i<=test; i++)
    {
        p=1;
        scanf("%d", &n);
        int array[n];
        for(j=0; j<n; j++)
        {
            c=0;
            scanf("%d", &array[j]);
            if(array[j]==2 && array[j]>p)
                p=2;
            for(l=2; l<array[j]; l++)
            {
                if(array[j]%l==0)
                {
                    c++;
                    break;
                }
            }
            if(array[j]>=p && c==0)
                p=array[j];
        }
        if(p==1)
            printf("-1\n");
        else printf("%d\n", p*p);
    }

    return 0;
}

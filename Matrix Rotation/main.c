#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, m, n, a, b, d, r, x, count, k;
    scanf("%d%d%d", &m, &n, &r);
    int mat[m][n];

    if(n>m)
        count=m/2;
    else count=n/2;

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            scanf("%d", &mat[i][j]);
    }

    for(i=0; i<r; i++)
    {
        a=m;
        b=0;
        d=n;
        for(k=0; k<count; k++)
        {
            a=a-1;
            d=d-1;
            x=mat[a][d];
            for(j=d; j>b; j--)
            {
                mat[a][j]=mat[a][j-1];
            }

            for(j=a; j>b; j--)
            {
                mat[j][b]=mat[j-1][b];
            }
            for(j=b; j<d; j++)
            {
                mat[b][j]=mat[b][j+1];
            }

            for(j=b; j<a-1; j++)
            {
                mat[j][d]=mat[j+1][d];
            }
            mat[a-1][d]=x;
            b++;
        }
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}

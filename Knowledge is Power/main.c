#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

int main()
{
    int order, c, i, j, k;
    uint64_t power, fsum;
    uint64_t sum=0;
    scanf("%d", &order);
    uint64_t mat1[order][order];
    uint64_t mat2[order][order];
    uint64_t mat3[order][order];

    for(i=0; i<order; i++)
    {
        for(j=0; j<order; j++)
        {
            scanf("%" PRIu64 "", &mat1[i][j]);
            mat3[i][j]=mat1[i][j];
        }
    }
    scanf("%" PRIu64 "", &power);

    for(c=1; c<power; c++)
    {
        for(i=0; i<order; i++)
        {
            for(j=0; j<order; j++)
            {
                mat2[i][j]=0;
                for(k=0; k<order ; k++)
                {
                    mat2[i][j]=mat1[i][k]*mat3[k][j]+mat2[i][j];
                }
            }
        }
        for(i=0; i<order; i++)
        {
            for(j=0; j<order; j++)
                mat3[i][j]=mat2[i][j];
        }
    }
    for(i=0; i<order; i++)
    {
        for(j=0; j<order; j++)
            sum=sum+mat2[i][j];
    }
    fsum=fmod(sum,(pow(10,9)+7));
    printf("%" PRIu64 "\n", sum);
    printf("%" PRIu64 "", fsum);

    return 0;
}

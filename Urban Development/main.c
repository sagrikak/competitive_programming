#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j;
    unsigned long long int lights=0;
    scanf("%d", &N);
    int road[N][4];
    int *count=(int *)calloc(N, sizeof(int));
    for(i=0; i<N; i++)
    {
        scanf("%d%d%d%d", &road[i][0], &road[i][1], &road[i][2], &road[i][3]);
    }
    for(i=0; i<N-1; i++)
    {
        for(j=i+1; j<N; j++)
        {
            if(road[i][0]==road[i][2] && road[j][1]==road[j][3])
            {
                if(road[j][0]<=road[i][0] && road[j][2]>=road[i][0] && road[i][1]<=road[j][1] && road[i][3]>=road[j][1])
                {
                    count[i]++; count[j]++;
                    lights++;
                }
                if(((road[i][0]==road[j][0]) || (road[i][0]==road[j][2])) && ((road[j][1]==road[i][1]) || (road[j][1]==road[i][3])))
                {
                    count[i]--; count[j]--;
                    lights--;
                }
            }
            else if(road[i][1]==road[i][3] && road[j][0]==road[j][2])
            {
                if(road[j][1]<=road[i][1] && road[j][3]>=road[i][1] && road[i][0]<=road[j][0] && road[i][2]>=road[j][0])
                {
                    count[i]++; count[j]++;
                    lights++;
                }
                if(((road[j][0]==road[i][0]) || (road[j][0]==road[i][2])) && ((road[i][1]==road[j][1]) || (road[i][1]==road[j][3])))
                {
                    count[i]--; count[j]--;
                    lights--;
                }
            }
        }
    }
    printf("%u\n", lights);
    for(i=0; i<N; i++)
        printf("%d ", count[i]);
    return 0;
}

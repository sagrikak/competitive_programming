#include <stdio.h>
#include <math.h>

int compare(int, int, int*);

int main()
{
    int n, k, N, l;
    scanf("%d",&n);
    N=pow(2,n)/2;
    int mat[((2*N*(2*N-1))/2)];
    printf("max=%d\n", 2*N*(2*N-1)/2-1);
    for(k=0; k<(2*N*(2*N-1))/2; k++)
    {
        scanf("%d",&mat[k]);
    }
    int arr[N*2];
    for(k=0; k<=N*2; k++)
    {
        arr[k]=k+1;
    }

    for(k=0; k<n; k++)
    {
        for(l=1; l<=N; l++)
        {
            arr[l-1]=compare(arr[2*l-1], arr[(2*l)-2], mat);
        }
        N=N/2;
    }
    //printf("\n%d", arr[0]);
    return 0;
}

int compare(int i, int j, int mat[])
{
    int I=(i-1)*(i-2)/2, J=j-1;
    printf("\n%d", I+J);
    if(mat[J+I] == 1)
    return i;
    else return j;
}

#include <stdio.h>
#include <conio.h>

int main()
{
    int i, n, test;
    scanf("%d", &test);
    for(i=1; i<=test; i++)
    {
        scanf("%d",&n);
        while(n>7)
            n=n-7;
        if(n==1)
            printf("The Father\n");
        if(n==2)
            printf("The Mother\n");
        if(n==3)
            printf("The Maiden\n");
        if(n==4)
            printf("The Crone\n");
        if(n==5)
            printf("The Warrior\n");
        if(n==6)
            printf("The Smith\n");
        if(n==7)
            printf("The Stranger\n");
    }
    getch();
    return 0;
}

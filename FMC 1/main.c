#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
        char arr[20];
        char x;
        int len=0;
        scanf(" %[^\n]s", &arr);
        len=strlen(arr);
        x=arr[len-1];
        if(len==1 && x=='2')
        {
            printf("NO\n");
        }
        else if(x%2==0)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

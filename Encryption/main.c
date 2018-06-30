#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char str[82];
    int l, r, c, i, j;
    scanf(" %[^\n]", &str);
    l=strlen(str);
    r=sqrt(l);
    c=r;
    i=0;
    if(r*c<l)
    {
        c=c+1;
    }
    if(r*c<l)
        r=r+1;
    while(i<l)
    {
        for(j=0; j<c; j++)
        {
            for(i=j; i<l; i=i+c)
            {
                printf("%c", str[i]);
            }
            printf(" ");
        }
    }
    return 0;
}

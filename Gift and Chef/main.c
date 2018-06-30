#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int fact(int x)
{
    int fact=1, i;
    for(i=2; i<=x; i++)
        fact=fact*i;
    return fact;
}

int c(int a, int b)
{
    int c;
    c=fact(a)*fact(b)/fact(b-a);
    return c;
}

int main()
{
    long long int t, i, lens, lenf, k, j, l=0, count=0, p;
    scanf("%d", &t);
    char s[300001], f[300001];
    for(i=0; i<t; i++)
    {
        count=0;
        scanf(" %[^\n]", &s);
        scanf(" %[^\n]", &f);
        lens=strlen(s);
        lenf=strlen(f);
        j=0;
        l=0;
        k=0;
        while(j<lens)
        {
            while(s[j]==f[k] && j<lens && k<lenf)
            {
                j++;
                l++;
                k++;
            }
            k=0;
            if(s[j]!=f[k])
                j++;
        }
        count=l/lenf;
        p=pow(2,count)-1;
        m=pow(10,9)+7;
        printf("%d\n", p%m);
    }
    return 0;
}

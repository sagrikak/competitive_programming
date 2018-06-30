#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int h, m, d;
    char a[7];
    char b[7];
    char c[20];
    scanf("%d%d", &h, &m);
    if(h==1)
    {
        strcpy(a, "one");
        strcpy(b, "two");
    }
    if(h==2)
    {
        strcpy(a, "two");
        strcpy(b, "three");
    }
    if(h==3)
    {
        strcpy(a, "three");
        strcpy(b, "four");
    }
    if(h==4)
    {
        strcpy(a, "four");
        strcpy(b, "five");
    }
    if(h==5)
    {
        strcpy(a, "five");
        strcpy(b, "six");
    }
    if(h==6)
    {
        strcpy(a, "six");
        strcpy(b, "seven");
    }
    if(h==7)
    {
        strcpy(a, "seven");
        strcpy(b, "eight");
    }
    if(h==8)
    {
        strcpy(a, "eight");
        strcpy(b, "nine");
    }
    if(h==9)
    {
        strcpy(a, "nine");
        strcpy(b, "ten");
    }
    if(h==10)
    {
        strcpy(a, "ten");
        strcpy(b, "eleven");
    }
    if(h==11)
    {
        strcpy(a, "eleven");
        strcpy(b, "twelve");
    }
    if(h==12)
    {
        strcpy(a, "twelve");
        strcpy(b, "one");
    }
    d=m;
    if(m>30)
        m=60-m;
    if(m==1)
        strcpy(c, "one");
    if(m==2)
        strcpy(c, "two");
    if(m==3)
        strcpy(c, "three");
    if(m==4)
        strcpy(c, "four");
    if(m==5)
        strcpy(c, "five");
    if(m==6)
        strcpy(c, "six");
    if(m==7)
        strcpy(c, "seven");
    if(m==8)
        strcpy(c, "eight");
    if(m==9)
        strcpy(c, "nine");
    if(m==10)
        strcpy(c, "ten");
    if(m==11)
        strcpy(c, "eleven");
    if(m==12)
        strcpy(c, "twelve");
    if(m==13)
        strcpy(c, "thirteen");
    if(m==14)
        strcpy(c, "fourteen");
    if(m==15)
        strcpy(c, "fifteen");
    if(m==16)
        strcpy(c, "sixteen");
    if(m==17)
        strcpy(c, "seventeen");
    if(m==18)
        strcpy(c, "eighteen");
    if(m==19)
        strcpy(c, "nineteen");
    if(m==20)
        strcpy(c, "twenty");
    if(m==21)
        strcpy(c, "twenty one");
    if(m==22)
        strcpy(c, "twenty two");
    if(m==23)
        strcpy(c, "twenty three");
    if(m==24)
        strcpy(c, "twenty four");
    if(m==25)
        strcpy(c, "twenty five");
    if(m==26)
        strcpy(c, "twenty six");
    if(m==27)
        strcpy(c, "twenty seven");
    if(m==28)
        strcpy(c, "twenty eight");
    if(m==29)
        strcpy(c, "twenty nine");

    if(m==0)
        printf("%s o' clock", a);
    else if(d<30)
    {
        if(d==1)
            printf("one minute past %s", a);
        else if(d==15)
            printf("quarter past %s", a);
        else printf("%s minutes past %s", c, a);
    }
    else if(d==30)
        printf("half past %s", a);
    else if(d>30)
    {
        if(d==45)
            printf("quarter to %s", b);
        else if(d==59)
            printf("one minute to %s", b);
        else
            printf("%s minutes to %s", c, b);
    }

    return 0;
}

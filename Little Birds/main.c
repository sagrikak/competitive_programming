#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, key, length, t;
    char str[100000];
    fgets(str,100000,stdin);
    scanf("%d", &key);
    length=strlen(str);

    if(length>0)
    {
        if(str[length-1]=='\n')
            length=length-1;
    }
    for(i=0; i<length-key; i++)
    {   t=str[i];
        str[i]=str[i+key];
        str[i+key]=t;
    }
    printf("%s", str);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main()
{
	int i, len, count=0;
	char str[101];
	scanf("%s", &str);
	len=strlen(str);
	for(i=1; i<len; i++)
	{
		if(str[i]<=90)
			count++;
	}
	if(count==len-1)
	{
		for(i=0; i<len; i++)
		{
			if(str[i]>90)
				str[i]=str[i]-32;
			else str[i]=str[i]+32;
		}
	}
	printf("%s", str);
	return 0;
}
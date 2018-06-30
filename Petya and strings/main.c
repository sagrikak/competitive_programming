#include <stdio.h>
#include <string.h>

int main()
{
	int len, i;
	char s1[101];
	char s2[101];
	scanf("%s", &s1);
	scanf("%s", &s2);
	len=strlen(s1);
	for(i=0; i<len; i++)
	{
		if(s1[i]<=90)
			s1[i]=s1[i]+32;
		if(s2[i]<=90)
			s2[i]=s2[i]+32;
		if(s1[i]<s2[i])
		{
			printf("-1");
			break;
		}
		else if(s1[i]>s2[i])
		{
			printf("1");
			break;
		}
		else if(s1[i]==s2[i])
		{
			//printf("%c %c\n", s1[i], s2[i]);
			if(i==len-1)
				printf("0");
		}
	}
	return 0;
}
#include <stdio.h>
#include <string.h>

int main()
{
	int i, len, count=0, j;
	char str[101];
	char temp;
	scanf(" %[^\n]s", &str);
	len=strlen(str);

	for(i=0; i<len-1; i++)
	{
		for(j=0; j<len-i-1; j++)
		{
			if(str[j]>str[j+1])
			{
				temp=str[j];
				str[j]=str[j+1];
				str[j+1]=temp;
			}
		}
	}

	for(i=0; i<len-1; i++)
	{
		if(str[i]!=str[i+1])
			count++;
	}

	if(count%2!=0)
		printf("CHAT WITH HER!");
	else printf("IGNORE HIM!");
	return 0;
}
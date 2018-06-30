#include <stdio.h>
#include <string.h>

int main()
{
	int len, i, count=0;
	char str[20];
	scanf("%s", &str);
	len=strlen(str);
	for(i=0; i<len; i++)
	{
		if(str[i]=='7' || str[i]=='4')
			count++;
	}
	if(count==4 || count==7)
		printf("YES");
	else printf("NO");
	return 0;
}
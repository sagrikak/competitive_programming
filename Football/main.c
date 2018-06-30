#include <stdio.h>
#include <string.h>

int main()
{
	char str[101];
	int i, len, count=1, x=1;
	scanf(" %[^\n]s", &str);
	len=strlen(str);
	for(i=1; i<len; i++)
	{
		if(str[i]==str[i-1])
		{
			count++;
		}
		else count=1;
		if(count>x)
			x=count;
	}
	if(x>=7)
		printf("YES");
	else printf("NO");
	return 0;
}
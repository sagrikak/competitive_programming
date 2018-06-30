#include <stdio.h>
#include <string.h>

int main()
{
	int len, t;
	char str[101];
	scanf("%d", &t);
	while(t)
	{
		scanf(" %[^\n]s", &str);
		len=strlen(str);
		if(len>10)
			printf("%c%d%c\n", str[0], len-2, str[len-1]);
		else
			printf("%s\n", str);
		t--;
	}
}
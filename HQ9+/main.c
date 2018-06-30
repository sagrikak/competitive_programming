#include <stdio.h>
#include <string.h>

int main()
{
	int i, len, count=0;
	char str[101];
	scanf(" %[^\n]s", &str);
	len=strlen(str);
	for(i=0; i<len; i++)
	{
		if(str[i]=='H' || str[i]=='Q' || str[i]=='9')
		{
			printf("YES");
			break;
		}
		else count++;
	}
	if(count==len)
		printf("NO");
	return 0;
}
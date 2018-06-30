#include <stdio.h>
#include <string.h>

int main()
{
	char str[1001];
	scanf("%s", &str);
	if(str[0]>90)
		str[0]=str[0]-32;
	printf("%s", str);
	return 0;
}
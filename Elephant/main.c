#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	if(n>5 && n%5!=0)
		printf("%d", n/5+1);
	else if(n>5 && n%5==0)
		printf("%d", n/5);
	else printf("1");
	return 0;
}
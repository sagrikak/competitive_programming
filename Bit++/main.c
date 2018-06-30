#include <stdio.h>

int main()
{
	int i, n, x=0;
	char exp[4];
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf(" %[^\n]s", &exp);
		if(exp[0]=='+' || exp[1]=='+' || exp[2]=='+')
			x++;
		else x--;
	}
	printf("%d", x);
	return 0;
}
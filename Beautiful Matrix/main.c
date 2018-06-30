#include <stdio.h>

int main()
{
	int i, j, x, a, b;
	for(i=1; i<=5; i++)
	{
		for(j=1; j<=5; j++)
		{
			scanf("%d", &x);
			if(x==1)
			{
				a=i;
				b=j;
			}
		}
	}

	if(a>3)
		x=a-3;
	else
		x=3-a;
	if(b>3)
		x=x+b-3;
	else 
		x=x+3-b;
	printf("%d", x);
	return 0;
}
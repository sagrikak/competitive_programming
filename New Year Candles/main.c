#include <stdio.h>

int main()
{
	int a, b, x, t=0;

	scanf("%d%d", &a, &b);
	x=a;
	t=a%b;
	while(a>=b)
	{
		a=a/b+t;
		x=x+a-t;
		t=a%b;
	}

	printf("%d", x);
	return 0;
}

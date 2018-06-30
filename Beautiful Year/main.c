#include <stdio.h>

int main()
{
	int i, a, b, c, d, y, t;
	scanf("%d", &y);
	while(1)
	{
		y++;
		t=y;
		d=t%10;
		t=t/10;
		c=t%10;
		t=t/10;
		b=t%10;
		t=t/10;
		a=t%10;
		if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
			break;
	}
	printf("%d", y);
	return 0;
}
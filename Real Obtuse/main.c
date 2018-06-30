#include <stdio.h>

int main()
{
	int t, b;
	scanf("%d", &t);
	for(b=0; b<t; b++)
	{
		int k, a, b, x, y;
		scanf("%d%d%d", &k, &a, &b);
		if(b<a)
		{
			x=b;
			b=a;
			a=x;
		}
		int aob=360*(b-a)/k;
		x=b-a-1;
        y=k-x-2;
        if(x<y)
            printf("%d\n", x);
        else if(x>y)
            printf("%d\n", y);
        else printf("0\n");
	}
}
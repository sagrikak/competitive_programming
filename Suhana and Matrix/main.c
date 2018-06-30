#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, t;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		int m, x=0, y=0, j;
		scanf("%d", &m);
		x=m/3;
		int k=m;
		//y=2*m/3;
		m=m%3;
		if(m==1)
			x++;
		else if(m==2)
		{
			x++;
		}
		y=k-x;
		printf("%d %d\n", x, y);
	}
}
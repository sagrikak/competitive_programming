#include <stdio.h>
#include <math.h>

int main()
{
	int t, b;
	scanf("%d", &t);
	for(b=0; b<t; b++)
	{
		int n, vs, ve;
		float ts, te;
		scanf("%d%d%d", &n, &vs, &ve);
		ts=sqrt(2)*(float)n/vs;
		te=(float)n*2/ve;
		if(ts<te)
			printf("Stairs\n");
		else printf("Elevator\n");
	}
}
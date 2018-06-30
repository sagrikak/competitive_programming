#include <stdio.h>

int main()
{
	int p, q, r, s, d, c1=0, c2=0, c3=0, c4=0, i;
	scanf("%d%d%d%d%d", &p, &q, &r, &s, &d);
	for(i=1; i<=d; i++)
	{
		if(i%p!=0 && i%q!=0 && i%r!=0 && i%s!=0)
			c1++;
	}
	printf("%d", d-c1);
	return 0;
}
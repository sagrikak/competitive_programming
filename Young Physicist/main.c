#include <stdio.h>

int main()
{
	int n, i, xx=0, y=0, z=0;
	scanf("%d", &n);
	int x[3*n];
	for(i=0; i<3*n; i++)
		scanf("%d", &x[i]);

	for(i=0; i<3*n; i=i+3)
	{
		xx=xx+x[i];
		y=y+x[i+1];
		z=z+x[i+2];
	}

	if(xx==0 && y==0 && z==0)
		printf("YES");
	else printf("NO");
	return 0;
}
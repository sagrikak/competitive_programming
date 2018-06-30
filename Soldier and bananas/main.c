#include <stdio.h>

int main()
{
	int k, n, w, x;
	scanf("%d%d%d", &k, &n, &w);
	x=k*w*(w+1)/2;
	if(x>n)
		printf("%d", x-n);
	else printf("0");
	return 0;
}
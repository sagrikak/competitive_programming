#include <stdio.h>
#include <inttypes.h>

int main()
{
	int64_t p=0, n=0, x;
	scanf("%"PRIu64"", &x);

	if(x%2!=0)
		printf("%"PRIu64"", (x-1)/2-x);
	else printf("%"PRIu64"", x/2);
	return 0;
}
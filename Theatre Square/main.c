#include <stdio.h>
#include <inttypes.h>

int main()
{
	int n, m, a;
	int64_t l, b;
	scanf("%d%d%d", &n, &m, &a);
	l=n/a;
	b=m/a;
	if(n%a!=0)
		l++;
	if(m%a!=0)
		b++;
	printf("%"PRIu64"\n", l*b);
	return 0;
}
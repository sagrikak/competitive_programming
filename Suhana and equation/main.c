#include <stdio.h>
#include <math.h>

int expmod(int n, int p, int m) {
   if (p == 0) return 1;
   int nm = n % m;
   long long r = expmod(nm, p / 2, m);
   r = (r * r) % m;
   if (p % 2 == 0) return r;
   return (r * nm) % m;
}

int main()
{
	int i, t;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		int m, n;
		scanf("%d%d", &n, &m);
		//int x=1, j;
		long long r = 1;
		for (int i = 1; i <= n; ++i)
		    r = (r + expmod(i, i, m)) % m;
		printf("%lld\n", r);
	}
}
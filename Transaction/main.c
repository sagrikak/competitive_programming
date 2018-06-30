#include <stdio.h>

int main()
{
	int t, q, i, j, m, n;
	scanf("%d%d", &t, &q);
	int ta[t];
	for(i=0; i<t; i++)
		scanf("%d", &ta[i]);

	for(i=0; i<q; i++)
	{
		scanf("%d%d", &m, &n);
		int count=0;
		for(j=0; j<t; j++)
		{
			if(ta[j]>=m)
				count++;
			if(count==n)
			{
				printf("%d\n", ta[j]);
				break;
			}
		}
		if(count<n)
			printf("-1\n");
	}
	return 0;
}
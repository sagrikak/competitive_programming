#include <stdio.h>

int main()
{
	int i, t;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		int n, m, j, k;
		scanf("%d%d", &n, &m);
		int pf[n][m], pt[n][m];
		for(j=0; j<n; j++)
		{
			for(k=0; k<m; k++)
				scanf("%d", &pf[j][k]);
		}
		for(j=0; j<n; j++)
		{
			for(k=0; k<m; k++)
				scanf("%d", &pt[j][k]);
		}
		
	}
}
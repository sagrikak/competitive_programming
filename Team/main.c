#include <stdio.h>

int main()
{
	int n, i, count1, count2=0;
	scanf("%d", &n);
	int one[n], two[n], three[n];

	for(i=0; i<n; i++)
	{
		scanf("%d", &one[i]);
		scanf("%d", &two[i]);
		scanf("%d", &three[i]);
	}

	for(i=0; i<n; i++)
	{
		count1=one[i]+two[i]+three[i];
		if(count1>=2)
			count2++;
	}

	printf("%d", count2);
}
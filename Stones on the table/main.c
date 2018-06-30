#include <stdio.h>
#include <string.h>

int main()
{
	int i, count=0, n;
	scanf("%d", &n);
	char str[n];
	scanf("%s", &str);
	for(i=1; i<n; i++)
	{
		if(str[i]==str[i-1])
			count++;
	}
	printf("%d", count);
	return 0;
}
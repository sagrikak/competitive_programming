#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[100001];

int comparator (const void * a, const void * b)
{
	return ( *(char*)a - *(char*)b );
}

int main()
{
	int len, i, j, x=0;
	char temp;
	scanf("%s", &s);
	len=strlen(s);

	qsort (s, len, sizeof(char), comparator );

	for(i=0; i<len-1; i++)
	{
		if(s[i]==s[i+1])
			x++;
	}
	printf("%d", x);
	return 0;
}
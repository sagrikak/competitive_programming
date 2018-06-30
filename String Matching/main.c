#include <stdio.h>
#include <string.h>
#include <inttypes.h>

int search(int x, int i, int j, char arr[])
{
	int a;
	for(a=i; a<=j; a++)
	{
		if(arr[a]==x+48)
			return 1;
	}
	return 0;
}

int main()
{
	char str[100001];
	scanf("%s", &str);
	int n, i, j, len, k, l=0;
	int64_t count=0;
	scanf("%d", &n);
	int x[n];
	for(i=0; i<n; i++)
		scanf("%d", &x[i]);
	len=strlen(str);
	for(i=0; i<len-n+1; i++)
	{
		for(j=i+n-1; j<len; j++)
		{
			l=0;
			for(k=0; k<n; k++)
			{
				//printf("%d\n", search(x[k], i, j, str));
				if(search(x[k], i, j, str))
					l++;
				else break;
			}
			if(l==n)
			{
				count+=len-j;
				j=len-1;
			}
		}
	}
	printf("%"PRIu64"", count);
}
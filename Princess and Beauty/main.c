#include <stdio.h>
#include <string.h>

int ispalindrome(char str[], int beg, int end)
{
	while(beg<end)
	{
		if(str[beg]!=str[end])
			return 0;
		beg++;
		end--;
	}
	return 1;
}

int main()
{
	int t, b;
	scanf("%d", &t);
	for(b=0; b<t; b++)
	{
		char str[100001];
		scanf("%s", &str);
		int i, j, len=strlen(str), k=0;
		for(i=len-1; i>=1; i--)
		{
			for(j=i-1; j>=0; j--)
			{
				if(ispalindrome(str, j, i))
				{
					k++;
					break;
				}
			}
		}
		if(k==0)
			printf("NO\n");
		else printf("YES\n");
	}
}
#include <stdio.h>
#include <string.h>

int main()
{
	int len, count=0;
	char x[101];
	char y[101];
	scanf("%s%s", &x, &y);
	len=strlen(x);
	int j=0, i;
	i=len-1;
	while(i>=0)
	{
		if(x[i]==y[j])
			count++;
		j++;
		i--;
	}
	if(count==len)
		printf("YES");
	else printf("NO");
	return 0;
}
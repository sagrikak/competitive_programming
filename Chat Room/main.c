#include <stdio.h>
#include <string.h>

int main()
{
	int len, i, j, k ,l, m, count=0;
	char str[101];
	scanf("%s", str);
	len=strlen(str);
	for(i=0; i<len-4; i++)
	{
		if(str[i]=='h')
		{
			for(j=i+1; j<len-3; j++)
			{
				if(str[j]=='e')
				{
					for(k=j+1; k<len-2; k++)
					{
						if(str[k]=='l')
						{
							for(l=k+1; l<len-1; l++)
							{
								if(str[l]=='l')
								{
									for(m=l+1; m<len; m++)
									{
										if(str[m]=='o')
										{
											count++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(count>0)
		printf("YES");
	else printf("NO");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i, t;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		char str[500];
		scanf(" %[^\n]s", &str);
		int len, j, k=0;
		len=strlen(str);
		for(j=0; j<len; j++)
		{
			if(j==0 || str[j-1]==' ')
			{
				if(str[j]>=97)
					str[j]=str[j]-32;
			}
			else if(str[j]!=' ' && str[j]<=90 && str[j]>=65)
				str[j]=str[j]+32;
			if(str[j]==' ')
				k++;
		}
		int l;
		char str2[500];
		if(k==0)
		{
			strcpy(str2, str);
			l=len;
		}
		else 
		{
			str2[0]=str[0];
			str2[1]='.';
			str2[2]=' ';
			l=3;
			for(j=1; j<len; j++)
			{
				if(str[j-1]==' ')
				{
					if(k==1)
					{
						while(j<len)
						{	str2[l]=str[j];
							l++;
							j++;
						}
					}
					if(k==2 && l<4)
					{
						str2[l]=str[j];
						str2[l+1]='.';
						str2[l+2]=' ';
						l=l+3;
					}
					else if(k==2 && l>4)
					{
						while(j<len)
						{	str2[l]=str[j];
							l++;
							j++;
						}
					}
				}
			}
		}
		for(j=0; j<l; j++)
			printf("%c", str2[j]);
		printf("\n");
	}
	return 0;
}
		
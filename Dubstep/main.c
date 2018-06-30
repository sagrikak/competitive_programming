#include <stdio.h>
#include <string.h>

int main()
{
	int i, j=0, len, x;
	char s[300];
	scanf(" %[^\n]s", &s);
	len=strlen(s);
	
	for(i=0; i<len; i++)
	{
		if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
		{
			if(i!=0 && i!=len-3)
			{
				s[i]=' ';
				x=2;
			}
			else
				x=3;
			for(j=i+3-x; j<len-x; j++)
				s[j]=s[j+x];
			len=len-x;
			i--;
		}
	}

	for(i=0; i<len; i++)
	{
		if(s[i]==' ' && s[i+1]==' ')
		{
			//printf("%d", i);
			for(j=i; j<len-1; j++)
				s[j]=s[j+1];
			len--;
			i--;
		}
	}	

	for(i=0; i<len; i++)
		printf("%c", s[i]);
	return 0;
}
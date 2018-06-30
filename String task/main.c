#include <stdio.h>
#include <string.h>

int delete(int i, int len);
int insert(int i, int len);
void replace(int i);

char str[205];

int main()
{
	int len, i;
	scanf(" %[^\n]s", &str);
	len=strlen(str);
	for(i=0; i<len; i++)
	{
		replace(i);
		if(str[i]=='a' || str[i]=='e' || str[i]=='o' || str[i]=='i' || str[i]=='u' || str[i]=='y')
		{
			len=delete(i, len);
			i--;
		}
		else 
		{
			len=insert(i, len);
			i++;
		}
	}
	for(i=0; i<len; i++)
		printf("%c", str[i]);
}

int delete(int i, int len)
{
	int k;
	for(k=i; k<len-1; k++)
	{
		str[k]=str[k+1];
	}
	len--;
	return len; 
}

int insert(int i, int len)
{
	int k;
	for(k=len; k>i; k--)
	{
		str[k]=str[k-1];
	}
	str[i]='.';
	len++;
	return len;
}

void replace(int i)
{
	if((int)str[i]<=90 && (int)str[i]>=65)
		str[i]=str[i]+32;
}
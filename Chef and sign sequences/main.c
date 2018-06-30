#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int t, i;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		char str[100001];
		int arr[100000];
		scanf("%s", &str);
		int len, j, p=0, n=0, k=0;
		len=strlen(str);
		for(j=0; j<len+1; j++)
		{
			p=0;
			n=0;
			while(str[j]=='<')
			{
				p++;
				j++;
				while(str[j]=='=')
					j++;
			}
			if(p>0)
			{
				arr[k]=p;
				k++;
			}
			while(str[j]=='>')
			{
				n++;
				j++;
				while(str[j]=='=')
					j++;
			}
			if(n>0)
			{
				arr[k]=n;
				k++;
				j--;
			}
		}
		int x=1, max=0;
		for(j=0; j<k; j++)
		{
			if(arr[j]>max)
				max=arr[j];
		}
		printf("%d\n", max+1);
	}
}
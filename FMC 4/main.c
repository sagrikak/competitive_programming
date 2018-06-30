#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i,p,q;

	scanf("%d",&i);
	scanf("%d",&p);
	scanf("%d",&q);

	char x[i],y[i],z[i];
	scanf("%s",&x);
	scanf("%s",&y);
	scanf("%s",&z);

	int cp1=0,cp2=0,comp=0;
	int count=strlen(x)-1;

	while()	while(cp1<p)
		{
			if(x[count]==y[count])
			{
				if(z[count]==1)
				{
					x[count]=complement(x[count]);
					comp++;
				}
				else;
			}
			else
			{
				if(z[count]==1);
				else
				{
					x[count]=complement(x[count]);
					comp++;
				}
			}
			count--;
		}

		while(cp2<q)
		{
			if(x[count]==y[count])
			{
				if(z[count]==1)
				{
					x[count]=complement(x[count]);
					comp++;
				}
				else;
			}
			else
			{
				if(z[count]==1);
				else
				{
					x[count]=complement(x[count]);
					comp++;
				}
			}
			count--;
		}
}

int complement(int x)
{
	if(x==1)
		return 0;
	else if(x==0)
		return 1;
}

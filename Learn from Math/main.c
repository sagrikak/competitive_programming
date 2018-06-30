#include <stdio.h>

int check(int x);

int main()
{
	int x, i, a;
	scanf("%d", &x);
	for(i=4; i<=x/2; i++)
	{
		if(check(i))
		{
			if(check(x-i))
			{
				a=i;
				break;
			}
			else 
				continue;
		}
	}
	printf("%d %d", a, x-a);
	return 0;
}

int check(int x)
{
	int count=0, i;
	for(i=2; i<=x/2; i++)
	{
		if(x%i==0)
			break;
		else
			count++;
	}
	//printf("%d\n", count);

	if(count==(x/2)-1)
		return 0;
	else return 1;
}
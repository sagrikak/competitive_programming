#include <stdio.h>

int main()
{
	int n;
	float x, a=5, temp;
	scanf("%d", &n);
	temp=n;
	while(a<temp)
	{
		temp=temp-a;
		a=a*2;
	}
	x=temp/(a/5);
	if(x>0 && x<=1)
		printf("Sheldon");
	else if(x>1 && x<=2)
		printf("Leonard");
	else if(x>2 && x<=3)
		printf("Penny");
	else if(x>3 && x<=4)
		printf("Rajesh");
	else if(x>4 && x<=5)
		printf("Howard");
	return 0;
}
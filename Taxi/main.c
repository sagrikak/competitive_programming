#include <stdio.h>

int main()
{
	int n, i, count1=0, count2=0, count3=0, count4=0, taxi, x;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &x);
		if(x==1)
			count1++;
		if(x==2)
			count2++;
		if(x==3)
			count3++;
		if(x==4)
			count4++;
	}
	taxi=count4;
	if(count3>count1)
	{
		taxi=taxi+count1;
		count3=count3-count1;
		count1=0;
	}
	else if(count1>=count3)
	{
		taxi=taxi+count3;
		count1=count1-count3;
		count3=0;
	}
	taxi=taxi+count2/2;
	count2=count2%2;
	if(count1%2==0 && count1>0)
	{
		taxi=taxi+count2;
		count1=count1-2*count2;
		count2=0;
	}
	else if(count1%2!=0 && count1>0)
	{
		taxi=taxi+count2;
		count1=count1-count2;
		count2=0;
	}
	taxi=taxi+count1/4;
	count1=count1%4;
	taxi=taxi+count2+count3;
	if(count1>0)
		taxi++;
	printf("%d", taxi);
	return 0;
}
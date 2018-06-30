#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int64_t mod(int64_t x)
{
	if(x<0)
		return -x;
	return x;
}

int64_t estimate(float temp, float ans)
{
	int64_t i=1;
	ans*=10;
	for(i=1; i<10; i++)
	{
		if((ans+i)*i>temp)
			break;
	}
	return i-1;
}

int64_t main()
{
	int64_t n, digits=0, k, divd, divs, rem=0, j, temp, dec;
	int64_t ans=0;
	printf("Enter the number to calculate square root and required number of decimal digits.\n");
	scanf("%"PRIu64"%"PRIu64"", &n, &dec);
	temp=n;
	while(n>0)
	{
		digits++;
		n/=10;
	}
	n=temp;
	k=digits;
	while(digits>-dec*2)
	{
		temp=(float)n;
		while(k>2)
		{
			temp/=100;
			k-=2;
		}
		if(digits>0)
			temp%=100;
		else temp=0;
		divd=rem*100+(int64_t)temp;
		divs=ans*2*10+estimate(divd, ans*2);
		ans=ans*10+divs%10;
		rem=divd-divs*(divs%10);
		//printf("%d ans=%d divd=%d divs=%d rem=%d\n", digits, ans, divd, divs, rem);
		digits-=k;
		k=2;
	}
	double sqrt=ans/pow(10, mod(digits/2));
	printf("%lf\n", sqrt);
}
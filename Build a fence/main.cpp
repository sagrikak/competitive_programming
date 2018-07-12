#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

float round(float x)
{
	x=x*100;
	int k=(int)x%10;
	if((float)(ceil(x)-x) > (float)(x-floor(x)))
		x=floor(x);
	else if((float)(ceil(x)-x) == (float)(x-floor(x)) && k%2==0)
		x=ceil(x);
	else if((float)(ceil(x)-x) == (float)(x-floor(x)) && k%2!=0)
		x=floor(x);
	else if((float)(ceil(x)-x) < (float)(x-floor(x)))
		x=ceil(x);
	return x/100;
}

int main()
{
	float n;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		float area;
		area=n*n/(2*3.141592);
		//area=round(area);
		cout<<fixed<<setprecision(2)<<area<<endl;
	}
}
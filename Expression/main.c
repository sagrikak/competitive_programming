#include <stdio.h>

int main()
{
	int x, i, y, z, temp=0;
	scanf("%d%d%d", &x, &y, &z);
	int arr[6];
	arr[0]=x+y+z;
	arr[1]=x+y*z;
	arr[2]=x*y+z;
	arr[3]=(x+y)*z;
	arr[4]=x*(y+z);
	arr[5]=x*y*z;
	for(i=0; i<6; i++)
	{
		if(arr[i]>temp)
			temp=arr[i];
	}
	printf("%d", temp);
	return 0;
}
#include <stdio.h>

int main()
{
	int n, i, x=0, y=0, t=0;
	scanf("%d", &n);
	int arr[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
		if(arr[i]%2==0)
			x++;
		else
			y++;
	}

	for(i=0; i<n; i++)
	{
		if(x<y)
		{
			if(arr[i]%2==0)
			{
				t=i+1;
				break;
			}
		}
		else if(x>y)
		{
			if(arr[i]%2!=0)
			{
				t=i+1;
				break;
			}
		}
	}

	printf("%d", t);
	return 0;
}
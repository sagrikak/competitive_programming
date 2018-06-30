#include <stdio.h>
#include <string.h>
#define max 100

int main()
{
	char str[max+1];
	int arr[max/2+1];
	int i, j, temp, k=0, len;
	scanf(" %[^\n]s", &str);
	len=strlen(str);
	for(i=0; i<len; i=i+2)
	{
		arr[k]=str[i]-48;
		k++;
	}
	//for(i=0; i<k; i++)
		//printf("%d ", arr[i]);
	for(i=0; i<k-1; i++)
	{
		for(j=0; j<k-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(i=0; i<k-1; i++)
		printf("%d+", arr[i]);
	printf("%d", arr[k-1]);
	return 0;
}
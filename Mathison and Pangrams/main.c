#include <stdio.h>
#include <string.h>

int main()
{
	int t, b;
	scanf("%d", &t);
	for(b=0; b<t; b++)
	{
		char str[50001];
		int arr[26], cost[26], i, tcost=0;
		for(i=0; i<26; i++)
		{
			scanf("%d", &cost[i]);
			arr[i]=0;
		}
		scanf("%s", &str);
		int len=strlen(str);
		for(i=0; i<len; i++)
		{
			if(str[i]=='a')
				arr[0]++;
			else if(str[i]=='b')
				arr[1]++;
			else if(str[i]=='c')
				arr[2]++;
			else if(str[i]=='d')
				arr[3]++;
			else if(str[i]=='e')
				arr[4]++;
			else if(str[i]=='f')
				arr[5]++;
			else if(str[i]=='g')
				arr[6]++;
			else if(str[i]=='h')
				arr[7]++;
			else if(str[i]=='i')
				arr[8]++;
			else if(str[i]=='j')
				arr[9]++;
			else if(str[i]=='k')
				arr[10]++;
			else if(str[i]=='l')
				arr[11]++;
			else if(str[i]=='m')
				arr[12]++;
			else if(str[i]=='n')
				arr[13]++;
			else if(str[i]=='o')
				arr[14]++;
			else if(str[i]=='p')
				arr[15]++;
			else if(str[i]=='q')
				arr[16]++;
			else if(str[i]=='r')
				arr[17]++;
			else if(str[i]=='s')
				arr[18]++;
			else if(str[i]=='t')
				arr[19]++;
			else if(str[i]=='u')
				arr[20]++;
			else if(str[i]=='v')
				arr[21]++;
			else if(str[i]=='w')
				arr[22]++;
			else if(str[i]=='x')
				arr[23]++;
			else if(str[i]=='y')
				arr[24]++;
			else if(str[i]=='z')
				arr[25]++;
		}
		for(i=0; i<26; i++)
		{
			if(arr[i]==0)
			{
				tcost+=cost[i];
			}
		}
		printf("%d\n", tcost);
	}
}
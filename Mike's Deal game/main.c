#include <stdio.h>
#include <string.h>

void quicksort(int firstIndex, int lastIndex, char p[]);

int pal(char x[], int len)
{
	int i=0, j=len-1;
	while(i<=j)
	{
		if(x[i]!=x[j])
			return 0;
		i++;
		j--;
	}
	return 1;
}

int main()
{
	int n, i, j=0, k;
	scanf("%d", &n);
	char co[n];
	for(i=0; i<n; i++)
	{
		int len=0;
		char str[1000001];
		scanf("%s", &str);
		len=strlen(str);
		if(pal(str, len))
		{
			co[j]=str[0];
			j++;
		}
	}
	
	quicksort(0, j-1, co);

	unsigned long long int count=1, x=0;
	for(i=0; i<j-1; i++)
	{
		//printf("%c", co[i]);

		while(co[i]==co[i+1])
		{
			count++;
			i++;
		}
		x=x+count*(count-1)/2;
		if(co[i]!=co[i+1])
			count=1;
	}
	printf("%llu", x);
	return 0;
}

void quicksort(int firstIndex, int lastIndex, char p[])
{
    int pivotIndex, index1, index2;
    char temp;

    if(firstIndex < lastIndex)
    {
        pivotIndex = firstIndex;
        index1 = firstIndex;
        index2 = lastIndex;

        while(index1 < index2)
        {
            while(p[index1] <= p[pivotIndex] && index1 < lastIndex)
            {
                index1++;
            }
            while(p[index2]>p[pivotIndex])
            {
                index2--;
            }

            if(index1<index2)
            {
                temp = p[index1];
                p[index1] = p[index2];
                p[index2] = temp;

            }
        }

        temp = p[pivotIndex];
        p[pivotIndex] = p[index2];
        p[index2] = temp;

        quicksort(firstIndex, index2-1, p);
        quicksort(index2+1, lastIndex, p);
        return;
    }
}
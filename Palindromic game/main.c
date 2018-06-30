#include <stdio.h>
#include <string.h>

void quicksort(char a[], int beg, int end)
{
    char pivot, temp;
    int x, i;
    if(beg>=end)
    return;
    
    temp=a[(beg+end)/2];
    a[(beg+end)/2]=a[end];
    a[end]=temp;
    
    pivot=a[end];
    x=beg;
    
    for(i=beg; i<end; i++)
    {
        if(a[i]<=pivot)
        {
            temp=a[x];
            a[x]=a[i];
            a[i]=temp;
            x++;
        }
    }
    temp=a[end];
    a[end]=a[x];
    a[x]=temp;
    quicksort(a, beg, x-1);
    quicksort(a, x+1, end);
}

int search(char x, char str[], int len)
{
	int beg=0, end=len-1, mid=(beg+end)/2;
	while(beg<=end)
	{
		//printf("%c %c %d\n", str[mid], x, mid);
		if(str[mid]==x)
			return 1;
		else if(str[mid]>x)
			end=mid-1;
		else
			beg=mid+1;
		mid=(beg+end)/2;
	}
	return 0;
}

int main()
{
	int p, b;
	scanf("%d",&p);
	for(b=0; b<p; b++)
	{
		int len, k=1, m=0, n=0, i;
		char s[501], t[501];
		scanf(" %[^\n]s", &s);
		scanf(" %[^\n]s", &t);
		len=strlen(s);
		if(strcmp(s, t)==0)
		{
			printf("B\n");
			continue;
		}
		quicksort(s, 0, len-1);
		quicksort(t, 0, len-1);
		for(i=0; i<len; i++)
		{
			if(search(t[i], s, len))
				m++;
			else break;
			//printf("%d %c", m, t[i]);
		}
		if(m==len)
		{
			printf("A\n");
			continue;
		}
		for(i=0; i<len-1; i++)
		{
			k=1;
			while(s[i]==s[i+1])
			{
				k++;
				i++;
			}
			if(k>=2 && search(s[i], t, len)==0)
			{
				n++;
				break;
			}
		}
		//printf("u=%d m=%d\n", u, m);
		if(n>0)
			printf("A\n");
		else printf("B\n");
	}
}
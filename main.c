#include <stdio.h>
#include <string.h>
#include <inttypes.h>

void quicksort(char r[], char s[], int beg, int end)
{
    int x, i;
    char pivot, temp;
    if(beg>=end)
    return;
    
    temp=s[(beg+end)/2];
    s[(beg+end)/2]=s[end];
    s[end]=temp;

    temp=r[(beg+end)/2];
    r[(beg+end)/2]=r[end];
    r[end]=temp;
    
    pivot=s[end];
    x=beg;
    
    for(i=beg; i<end; i++)
    {
        if(s[i]<=pivot)
        {
            temp=s[x];
            s[x]=s[i];
            s[i]=temp;
            temp=r[x];
            r[x]=r[i];
            r[i]=temp;
            x++;
        }
    }
    temp=s[end];
    s[end]=s[x];
    s[x]=temp;
    temp=r[end];
    r[end]=r[x];
    r[x]=temp;
    quicksort(r, s, beg, x-1);
    quicksort(r, s, x+1, end);
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
    	char p[1001], q[1001], r[1001], s[1001];
    	scanf("%s%s", &p, &q);
    	int j, k=0;
    	for(j=0; j<strlen(p); j++)
    	{
    		if(p[j]!=q[j])
    		{
    			r[k]=p[j];
    			s[k]=q[j];
    			k++;
    		}
    	}
    	quicksort(r, s, 0, k-1);
    	int l=0;
    	for(j=0; j<k-1; j++)
    	{
    		if(s[j]==s[j+1] && r[j]!=r[j+1])
    		{
    			l=1;
    			break;
    		}
    	}
    	if(l==0)
    		printf("YES\n");
    	else if(l==1)
    		printf("NO\n");
    }
    return 0;
}

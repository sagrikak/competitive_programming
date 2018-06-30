#include <stdio.h>

void quicksort(int firstIndex, int lastIndex, int p[])
{
    int pivotIndex, index1, index2;
    int temp;

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

int search(int x, int m, int p[])
{
	int beg=0, end=m-1, mid=(beg+end)/2;
	while(beg<=end)
	{
		if(x>p[mid])
			beg=mid+1;
		else if(x<p[mid])
			end=mid-1;
		else if(x==p[mid])
			return 1;
		mid=(beg+end)/2;
	}
	return 0;
}

int main()
{
	int m, n, t, i, j;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		int count=0;
		scanf("%d%d", &n, &m);
		int first[n];
		int second[m];
		for(j=0; j<n; j++)
			scanf("%d", &first[j]);
		for(j=0; j<m; j++)
			scanf("%d", &second[j]);

		quicksort(0, m-1, second);

		for(j=0; j<n; j++)
		{
			if(search(first[j], m, second))
				count++;
		}
		printf("%d\n", count);
	} 
	return 0;
}
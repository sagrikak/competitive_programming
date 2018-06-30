#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void quicksort(int day[], int lec[], int sad[], int beg, int end)
{
	int pivot, x, i, temp, temp2, temp3;
	if(beg>=end)
		return;

	temp=sad[(beg+end)/2];
	temp2=day[(beg+end)/2];
	temp3=lec[(beg+end)/2];

	sad[(beg+end)/2]=sad[end];
	day[(beg+end)/2]=day[end];
	lec[(beg+end)/2]=lec[end];

	sad[end]=temp;
	day[end]=temp2;
	lec[end]=temp3;

	pivot=sad[end];
	x=beg;

	for(i=beg; i<end; i++)
	{
		if(sad[i]>=pivot)
		{
			temp=sad[x];
			temp2=day[x];
			temp3=lec[x];

			sad[x]=sad[i];
			day[x]=day[i];
			lec[x]=lec[i];

			sad[i]=temp;
			day[i]=temp2;
			lec[i]=temp3;
			x++;
		}
	}
	temp=sad[end];
	temp2=day[end];
	temp3=lec[end];

	sad[end]=sad[x];
	day[end]=day[x];
	lec[end]=lec[x];

	sad[x]=temp;
	day[x]=temp2;
	lec[x]=temp3;

	quicksort(day, lec, sad, beg, x-1);
	quicksort(day, lec, sad, x+1, end);
}

int main()
{
	int i, t;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		int n, d, j;
		scanf("%d%d", &n, &d);
		int day[n], lec[n], sad[n];
		int* tt=(int*)calloc(sizeof(int), d+1);
		for(j=0; j<n; j++)
		{
			scanf("%d%d%d", &day[j], &lec[j], &sad[j]);
		}
		int64_t min=0, k;
		quicksort(day, lec, sad, 0, n-1);
		/*for(j=0; j<n; j++)
		{
			printf("%d %d %d\n", day[j], lec[j],  sad[j]);
		}*/
		int end=d, beg=1;
		for(j=0; j<n; j++)
		{
			if(day[j]<beg)
				k=beg;
			else k=day[j];
			while(lec[j]>0 && k<=end)
			{
				//printf("k=%d\n", k);
				if(tt[k]==0)
				{
					if(k==end)
						end--;
					if(k==beg)
						beg++;
					tt[k]=j+1;
					lec[j]--;
				}
				k++;
			}
			min=lec[j]*sad[j]+min;
		}
		//for(j=0; j<n; j++)
			//printf("%d ", lec[j]);
		printf("%"PRIu64"\n", min);
	}
}
#include <iostream>
#include <string.h>
using namespace std;

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

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		char str[1000000];
		cin>>str;
		int arr[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		char ans[27];
		int len=strlen(str), x, size=0;
		for(int j=0; j<len; j++)
		{
			int l=str[j]-48;
			arr[l]++;
		}
		for(int j=6; j<10; j++)
		{
			//cout<<"j="<<j<<" "<<arr[j]<<endl;
			if(arr[j]>1 && j!=9)
			{
				x=j*10+j;
				//cout<<"x="<<x<<endl;
				if(x>=65 && x<=90)
				{
					ans[size]=(char)x;
					size++;
				}
			}
			if(arr[j]>0)
			{
				for(int k=0; k<10; k++)
				{
					//cout<<"k="<<k<<" "<<arr[k]<<endl;
					if(arr[k]>0 && k!=j)
					{
						x=j*10+k;
						//cout<<"x="<<x<<endl;
						if(x>=65 && x<=90)
						{
							ans[size]=(char)x;
							size++;
						}
					}
				}
			}
		}

		quicksort(ans, 0, size-1);
		
		for(int j=0; j<size; j++)
			cout<<ans[j];
		cout<<endl;
	}
}
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n, q, lower, upper;
	cin>>n>>q>>lower>>upper;
	int arr[n];
	memset(arr, 0, sizeof(arr));
	for(int i=0; i<q; i++)
	{
		int x, a, b, ans=0, max;
		cin>>x>>a>>b;
		if(x==1)
			arr[a-1] = b;
		else
		{
			for(int j=a-1; j<b; j++)
			{
				for(int k=j; k<b; k++)
				{
					max=0;
					for(int l=j; l<=k; l++)
					{
						if(arr[l]>max)
							max=arr[l];
					}
					if(max>=lower && max<=upper)
					{
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
}
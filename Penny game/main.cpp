#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=1; i<=t; i++)
	{
		int j;
		cin>>j;
		char str[41];
		int arr[8]={0,0,0,0,0,0,0,0};
		cin>>str;
		for(int j=0; j<38; j++)
		{
			if(str[j]=='T' && str[j+1]=='T' && str[j+2]=='T')
				arr[0]++;
			else if(str[j]=='T' && str[j+1]=='T' && str[j+2]=='H')
				arr[1]++;
			else if(str[j]=='T' && str[j+1]=='H' && str[j+2]=='T')
				arr[2]++;
			else if(str[j]=='T' && str[j+1]=='H' && str[j+2]=='H')
				arr[3]++;
			else if(str[j]=='H' && str[j+1]=='T' && str[j+2]=='T')
				arr[4]++;
			else if(str[j]=='H' && str[j+1]=='T' && str[j+2]=='H')
				arr[5]++;
			else if(str[j]=='H' && str[j+1]=='H' && str[j+2]=='T')
				arr[6]++;
			else if(str[j]=='H' && str[j+1]=='H' && str[j+2]=='H')
				arr[7]++;
		}

		cout<<i<<" ";
		for(int j=0; j<8; j++)
			cout<<arr[j]<<" ";
		cout<<endl;
	}
}
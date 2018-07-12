#include <iostream>
using namespace std;

int main()
{
	int a, d;
	while(1)
	{
		cin>>a>>d;
		if(a==0 && d==0)
			break;
		int mina=100000, x, k=0;
		for(int i=0; i<a; i++)
		{
			cin>>x;
			if(mina>x)
				mina=x;
		}
		for(int i=0; i<d; i++)
		{
			cin>>x;
			if(mina>=x)
				k++;
		}
		if(k<2)
			cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
}
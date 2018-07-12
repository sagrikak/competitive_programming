#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int god, mech, temp1=0, temp2=0;
		cin>>god>>mech;
		int ag[god], am[mech];
		for(int j=0; j<god; j++)
		{
			cin>>ag[j];
			if(ag[j]>temp1)
				temp1=ag[j];
		}
		for(int j=0; j<mech; j++)
		{
			cin>>am[j];
			if(am[j]>temp2)
				temp2=am[j];
		}
		if(temp2>temp1)
			cout<<"MechaGodzilla"<<endl;
		else cout<<"Godzilla"<<endl;
	}
}
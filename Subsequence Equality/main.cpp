#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int k=0;
		string str;
		cin>>str;
		int len=str.length();
		int* arr=(int*)calloc(26, sizeof(int));
		for(int j=0; j<len; j++)
		{
			arr[(int)str.at(j)-97]++;
		}
		for(int j=0; j<len; j++)
		{
			if(arr[(int)str.at(j)-97] > 1)
				k++;
		}
		if(k>1)
			cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}
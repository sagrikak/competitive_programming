#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int temp;
	int x=0;
	for(int i=0; i<n; i++)
	{
		scanf("%d", &temp);
		x=x^temp;
	}
	cout<<x;
}
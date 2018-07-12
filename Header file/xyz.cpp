#include <iostream>
#include "xyz.h"
using namespace std;

xyz::xyz(int a, int b)
: regvar(a), constvar(b)//constructor
{
	cout<<"constructor"<<endl;
}

void xyz::print()
{
	cout<<"regular var is "<<regvar<<endl;
	cout<<"constant var is "<<constvar<<endl;
}
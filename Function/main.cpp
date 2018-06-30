#include <iostream>
using namespace std;

int main()
{
	long long int x, p, n;

	cin >> x;

	if(x%2!=0)
		cout << x/2-x;
	else cout << x/2;
	return 0;
}
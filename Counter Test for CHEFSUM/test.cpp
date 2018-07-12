#include <iostream>
#include <vector>
using namespace std;

int wrongSolver(vector <unsigned int> a) 
{
	int n = a.size();
	vector<unsigned int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	unsigned int mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		unsigned int val = prefSum[i] + sufSum[i];
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	return where;
}

int main()
{
	int n;
	cin>>n;
	vector <unsigned int> arr;
	unsigned int x, y;
	cin>>y>>x;
	arr.push_back(y);
	for(int i=1; i<n; i++)
	{
		arr.push_back(x);
	}
	int z = wrongSolver(arr);
	cout<<z<<endl;
}
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<double>v;
int n;
int main()
{
	cin >> n;
	v.resize(n);
	for (int i = 0; i<n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	double res = v[0];
	for (int i = 1; i<v.size(); i++)
	{
		res = (res + v[i]) / 2;
	}
	printf("%d\n", int(res));
	return 0;
}

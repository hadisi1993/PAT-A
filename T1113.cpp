#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 1e5 + 5;
long long int a[maxn];
int n;
int main()
{
	cin >> n;
	long long sum = 0, sum1 = 0;
	for (int i = 0; i<n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i<n; i++)
	{
		sum += a[i];
		if (i<n / 2) sum1 += a[i];
	}
	cout << (n & 1) << " " << sum - 2 * sum1 << endl;
	return 0;
}

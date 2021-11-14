#include<iostream>
#include<algorithm>
using namespace std;
int a[100100];
int main()
{
	int n, i, t;
	cin >> n;
	for (i = 0; i<n; i++)
	{
		cin >> t;
		a[t] = i;
	}
	int cnt = 0;
	for (int i = 0; i<n; i++)
	{
		while (a[0] != 0)
		{
			swap(a[0], a[a[0]]);
			cnt++;
		}
		if (a[i] != i)
		{
			swap(a[0], a[i]);
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}

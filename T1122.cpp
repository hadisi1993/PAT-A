#include<iostream>
#include<set>
#include<vector>
using namespace std;
int n, m;
int flag1, flag2;
int main()
{
	int a[205][205] = { 0 };
	cin >> n >> m;
	int x, y;
	for (int i = 0; i<m; i++)
	{
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	int k;
	cin >> k;
	for (int i = 0; i<k; i++)
	{
		flag1 = flag2 = 1;
		int cnt;
		cin >> cnt;
		vector<int>v(cnt);
		set<int>s;
		for (int j = 0; j<cnt; j++)
		{
			cin >> v[j];
			s.insert(v[j]);
		}
		if (s.size() != n || cnt - 1 != n || v[0] != v[cnt - 1]) flag1 = 0;
		for (int j = 0; j<cnt - 1; j++)
		if (!a[v[j]][v[j + 1]]) flag2 = 0;
		printf("%s\n", flag1&&flag2 ? "YES" : "NO");
	}
	return 0;
}

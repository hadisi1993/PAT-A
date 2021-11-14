#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
unordered_set<int>p[60], s;
int main()
{
	int n, m, v, k, p1, p2, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		for (int j = 0; j<m; j++)
		{
			scanf("%d", &v);
			p[i].insert(v);
		}
	}
	cin >> k;
	for (int i = 0; i<k; i++)
	{
		scanf("%d %d", &p1, &p2);
		cnt = 0;
		for (auto it = p[p1].begin(); it != p[p1].end(); it++)
		{
			if (p[p2].count(*it) == 1)
				cnt++;
		}
		double res = (double)(cnt) / (p[p1].size() + p[p2].size() - cnt);
		printf("%.1lf\%\n", res * 100);
	}
	return 0;
}

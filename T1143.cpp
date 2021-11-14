#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n, m;
int main()
{
	scanf("%d %d", &m, &n);
	vector<int>pre(n);
	map<int, bool>mp;
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &pre[i]);
		mp[pre[i]] = true;
	}
	int u, v;
	for (int i = 0; i<m; i++)
	{
		scanf("%d %d", &u, &v);
		int a;
		for (int j = 0; j<n; j++)
		{
			if ((u <= pre[j] && v >= pre[j]) || (v <= pre[j] && u >= pre[j]))
			{
				a = pre[j];
				break;
			}
		}
		if (!mp[u] && !mp[v])
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if (!mp[u] || !mp[v])
			printf("ERROR: %d is not found.\n", mp[u] ? v : u);
		else if (a == u || a == v)
			printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
		else
			printf("LCA of %d and %d is %d.\n", u, v, a);
	}
	return 0;
}

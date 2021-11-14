#include <iostream>
#include<algorithm>
using namespace std;
int e[1005][1005];
int vis[1005];
int n, m, k;
void dfs(int node)
{
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i] && e[node][i])
		{
			vis[i] = 1;
			dfs(i);
		}
	}
	return;
}
int main()
{
	int v1, v2;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i<m; i++)
	{
		scanf("%d %d", &v1, &v2);
		e[v1][v2] = e[v2][v1] = 1;
	}
	for (int i = 0; i<k; i++)
	{
		int cnt = 0, op;
		scanf("%d", &op);
		fill(vis, vis + 1005, 0);
		vis[op] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				vis[i] = 1;
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt - 1);
	}
	return 0;
}

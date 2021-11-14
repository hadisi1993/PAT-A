#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, s, d;
vector<int>pre[505], path, tmpath;
int e[505][505];
int c[505][505];
int vis[505];
int dis[505];
const int inf = 999999;
int mincost = inf;
void dfs(int node, int sumcost)
{
	tmpath.push_back(node);
	if (node == s)
	{
		if (sumcost<mincost)
		{
			mincost = sumcost;
			path = tmpath;
		}
		tmpath.pop_back();
		return;
	}
	for (int i = 0; i<pre[node].size(); i++)
	{
		int p = pre[node][i];
		dfs(p, sumcost + c[p][node]);
	}
	tmpath.pop_back();
	return;
}
int main()
{
	fill(e[0], e[0] + 505 * 505, inf);
	fill(dis, dis + 505, inf);
	scanf("%d %d %d %d", &n, &m, &s, &d);
	int a, b, v, w;
	for (int i = 0; i<m; i++)
	{
		scanf("%d %d %d %d", &a, &b, &v, &w);
		e[a][b] = e[b][a] = v;
		c[a][b] = c[b][a] = w;
	}
	dis[s] = 0;
	for (int i = 0; i<n; i++)
	{
		int k;
		int mindist = inf;
		for (int j = 0; j<n; j++)
		{
			if (!vis[j])
			{
				if (mindist>dis[j])
				{
					k = j;
					mindist = dis[j];
				}
			}
		}
		vis[k] = 1;
		if (k == d)
			break;
		for (int j = 0; j<n; j++)
		{
			if (!vis[j])
			{
				if (dis[j]>dis[k] + e[j][k])
				{
					pre[j].clear();
					dis[j] = dis[k] + e[j][k];
					pre[j].push_back(k);
				}
				else if (dis[j] == dis[k] + e[j][k])
				{
					pre[j].push_back(k);
				}
			}
		}
	}
	dfs(d, 0);
	for (int i = path.size() - 1; i >= 0; i--)
	{
		printf("%d ", path[i]);
	}
	printf("%d %d", dis[d], mincost);
	return 0;
}

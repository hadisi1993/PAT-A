#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, st, ed;
int d[510][510];
int c[510][510];
bool vis1[510];
bool vis2[510];
int dis[510];
int cost[510];
int ins[510]; // 节点
int w[510]; // 最短路的花费时间
vector<int>path1, path2;
int pre1[510], pre2[510];
const int inf = 999999;
void dfs1(int node)
{
	path1.push_back(node);
	if (node == st)
		return;
	dfs1(pre1[node]);
}
void dfs2(int node)
{
	path2.push_back(node);
	if (node == st)
		return;
	dfs2(pre2[node]);
}
int main()
{
	fill(d[0], d[0] + 510 * 510, inf);
	fill(c[0], c[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	fill(cost, cost + 510, inf);
	fill(w, w + 510, inf);
	fill(ins, ins + 510, inf);
	scanf("%d %d", &n, &m);
	int a, b, o, v1, v2;
	for (int i = 0; i<m; i++)
	{
		scanf("%d %d %d %d %d", &a, &b, &o, &v1, &v2);
		d[a][b] = v1;
		c[a][b] = v2;
		if (!o)
		{
			d[b][a] = v1;
			c[b][a] = v2;
		}
	}
	scanf("%d %d", &st, &ed);
	dis[st] = cost[st] = w[st] = ins[st] = 0;
	for (int i = 0; i<n; i++)
	{
		int k = -1;
		int mindis = inf;
		for (int j = 0; j<n; j++)
		{
			if (!vis1[j])
			{
				if (dis[j]<mindis)
				{
					k = j;
					mindis = dis[j];
				}
			}
		}
		vis1[k] = true;
		if (k == ed) break;
		for (int j = 0; j<n; j++)
		{
			if (!vis1[j])
			{
				if (dis[j]>dis[k] + d[k][j] || (dis[j] == dis[k] + d[k][j] && w[j]>w[k] + c[k][j]))
				{
					pre1[j] = k;
					dis[j] = dis[k] + d[k][j];
					w[j] = w[k] + c[k][j];
				}
			}
		}
	}
	for (int i = 0; i<n; i++)
	{
		int k = -1;
		int mintime = inf;
		for (int j = 0; j<n; j++)
		{
			if (!vis2[j])
			{
				if (mintime>cost[j])
				{
					k = j;
					mintime = cost[j];
				}
			}

		}
		vis2[k] = true;
		if (k == ed)break;
		for (int j = 0; j<n; j++)
		{
			if (cost[j]>cost[k] + c[k][j] || (cost[j] == cost[k] + c[k][j] && ins[j]>ins[k] + 1))
			{
				pre2[j] = k;
				ins[j] = ins[k] + 1;
				cost[j] = cost[k] + c[k][j];
			}
		}
	}
	dfs1(ed);
	dfs2(ed);
	if (path1 == path2)
	{
		printf("Distance = %d; Time = %d: %d", dis[ed], cost[ed], path1[path1.size() - 1]);
		for (int i = path1.size() - 2; i >= 0; i--)
			printf(" -> %d", path1[i]);
	}
	else
	{
		printf("Distance = %d: %d", dis[ed], path1[path1.size() - 1]);
		for (int i = path1.size() - 2; i >= 0; i--)
			printf(" -> %d", path1[i]);
		printf("\nTime = %d: %d", cost[ed], path2[path2.size() - 1]);
		for (int i = path2.size() - 2; i >= 0; i--)
			printf(" -> %d", path2[i]);
	}
	return 0;
}

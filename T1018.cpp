#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int e[510][510];
int dis[510];
bool vis[510];
const int inf = 99999999;
vector<int>tmpath, path;
int c, n, ed, m;
int num[510];
int mins = inf, minb = inf; // 最小配送,最小收回
int anss, ansb;
vector<int>pre[510];
void dfs(int index)
{
	if (index == 0)
	{
		int r = 0, b = 0;
		for (int i = tmpath.size() - 1; i >= 0; i--)
		{
			if (b + num[tmpath[i]] >= 0)
				b = b + num[tmpath[i]];
			else
			{
				r -= (b + num[tmpath[i]]);
				b = 0;
			}
		}
		if (r<mins || (r == mins&&b<minb))
		{
			mins = r;
			minb = b;
			path = tmpath;
		}
		return;
	}
	for (int i = 0; i<pre[index].size(); i++)
	{
		tmpath.push_back(pre[index][i]);
		dfs(pre[index][i]);
		tmpath.pop_back();
	}
}
int main()
{
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	scanf("%d %d %d %d", &c, &n, &ed, &m);
	for (int i = 1; i<n + 1; i++)
	{
		scanf("%d", &num[i]);
		num[i] = num[i] - c / 2;
	}
	int v1, v2, v;
	for (int i = 0; i<m; i++)
	{
		scanf("%d %d %d", &v1, &v2, &v);
		e[v1][v2] = e[v2][v1] = v;
	}
	//开始Djstkra
	dis[0] = 0;
	for (int i = 0; i<n + 1; i++)
	{
		int mindist = inf;
		int k;
		for (int j = 0; j<n + 1; j++)
		{
			if (!vis[j])
			{
				if (dis[j]<mindist)
				{
					k = j;
					mindist = dis[j];
				}
			}
		}
		vis[k] = true;
		if (k == ed)
			break;
		for (int j = 0; j<n + 1; j++)
		{
			if (!vis[j])
			{
				if (dis[j]>dis[k] + e[k][j])
				{
					dis[j] = dis[k] + e[k][j];
					pre[j].clear();
					pre[j].push_back(k);
				}
				else if (dis[j] == dis[k] + e[k][j])
				{
					pre[j].push_back(k);
				}
			}
		}
	}
	tmpath.push_back(ed);
	dfs(ed);
	printf("%d ", mins);
	for (int i = path.size() - 1; i >= 0; i--)
	if (i == 0)
		printf("%d", path[i]);
	else
		printf("%d->", path[i]);
	printf(" %d", minb);
	return 0;
}

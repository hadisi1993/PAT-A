#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct NODE
{
	int w;
	vector<int>child;
};
int target;
vector<NODE>v;
vector<int>path;
bool cmp(int a, int b)
{
	return v[a].w>v[b].w;
}
void dfs(int index, int nodeNum, int sum)
{
	if (sum>target)
		return;
	if (sum == target)
	{
		if (v[index].child.size() != 0)
			return;      // 非叶子节点直接返回
		for (int i = 0; i<nodeNum; i++)
			printf("%d%c", v[path[i]].w, i != nodeNum - 1 ? ' ' : '\n');
		return;
	}
	for (int i = 0; i<v[index].child.size(); i++)
	{
		int node = v[index].child[i];
		path[nodeNum] = node;
		dfs(node, nodeNum + 1, sum + v[node].w);
	}
}
int main()
{
	int n, m, node, k;
	scanf("%d %d %d", &n, &m, &target);
	v.resize(n), path.resize(n);
	for (int i = 0; i<n; i++)
		scanf("%d", &v[i].w);
	for (int i = 0; i<m; i++)
	{
		scanf("%d %d", &node, &k);
		v[node].child.resize(k);
		for (int j = 0; j<k; j++)
			scanf("%d", &v[node].child[j]);
		sort(v[node].child.begin(), v[node].child.end(), cmp);
	}
	dfs(0, 1, v[0].w);
	return 0;
}

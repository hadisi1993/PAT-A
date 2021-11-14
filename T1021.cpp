#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
/*这道题有一个隐含条件，就是
无论从哪个节点开始遍历，距离该节点最远的节点一定是一个deepest root,因为
1. 这个节点在这个图最长的路径上，那距离它最远的节点一定是一个deepest root,否则它所在的路径就不是最长
的路径
2. 这个节点不再这个图的最长路径上，那距离它最远的节点一定是一个deepest root ,否则它就在最长路径上
3，综上，距离该节点最远的节点一定是一个deepest root,由此，进行两边dfs遍历，第一遍找一个deepest root,
第二遍从这个节点开始遍历，查找所有最长节点*/
using namespace std;
int n, maxheight;
vector<vector<int>>v;  //用vector数组来模拟树
bool visit[10010];
set<int>s;
vector<int>temp;
void dfs(int node, int height)
{
	if (height>maxheight)
	{
		temp.clear();  // 一个deepest root
		temp.push_back(node);
		maxheight = height;
	}
	else if (height == maxheight)
		temp.push_back(node);
	visit[node] = true;
	for (int i = 0; i<v[node].size(); i++)
	{
		if (visit[v[node][i]] == false)
			dfs(v[node][i], height + 1);
	}
}
int main()
{
	scanf("%d", &n);
	v.resize(n + 1);  // 将v重置大小
	int a, b, cnt = 0, s1 = 0;
	for (int i = 0; i<n - 1; i++)
	{
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false)
		{
			dfs(i, 1);
			if (i == 1)
			{
				if (temp.size() != 0)
					s1 = temp[0];
				for (int j = 0; j<temp.size(); j++)
					s.insert(temp[j]);
			}
			cnt++;
		}
	}
	if (cnt >= 2)
		printf("Error: %d components", cnt);
	else
	{
		temp.clear();
		maxheight = 0;
		fill(visit, visit + 10010, false);
		dfs(s1, 1);
		for (int i = 0; i<temp.size(); i++)
			s.insert(temp[i]);
		for (auto it = s.begin(); it != s.end(); it++)
			printf("%d\n", *it);
	}
	return 0;
}

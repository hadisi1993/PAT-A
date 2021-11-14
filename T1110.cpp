#include <iostream>
#include<cstdlib>
#include<string>
using namespace std;
int n;
int maxn = -1;
int maxid;
int have[250];
struct Node
{
	int l = -1, r = -1;
}node[250];
void dfs(int root, int index)
{
	if (maxn<index)
	{
		maxn = index;
		maxid = root;
	}
	if (node[root].l != -1)
		dfs(node[root].l, 2 * index);
	if (node[root].r != -1)
		dfs(node[root].r, 2 * index + 1);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		string l, r;
		cin >> l >> r;
		if (l != "-")
		{
			node[i].l = stoi(l);
			have[node[i].l] = 1;
		}
		if (r != "-")
		{
			node[i].r = stoi(r);
			have[node[i].r] = 1;
		}
		getchar();
	}
	int root = 0;
	while (have[root])
	{
		root++;
	}
	dfs(root, 1);
	if (maxn == n)
		printf("YES %d", maxid);
	else
		printf("NO %d", root);
	return 0;
}

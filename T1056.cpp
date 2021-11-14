#include<bits/stdc++.h>   //万能头函数
using namespace std;
const int maxn = 1e4 + 10;
struct node
{
	int weight, rk;
}mice[maxn];
int np, m;
int main()
{
	scanf("%d %d", &np, &m);
	for (int i = 0; i<np; i++)
	{
		scanf("%d", &mice[i].weight);
	}
	queue<int>q;
	for (int i = 0; i<np; i++)
	{
		int x;
		scanf("%d", &x);
		q.push(x);
	}
	int tmp = np, group;
	while (q.size() != 1)
	{
		if (tmp%m == 0)
			group = tmp / m;
		else
			group = tmp / m + 1;
		for (int i = 0; i<group; i++)
		{
			int k = q.front();
			for (int j = 0; j<m; j++)
			{
				if (i*m + j >= tmp)
					break;
				int v = q.front();
				q.pop();
				if (mice[v].weight>mice[k].weight)
					k = v;
				mice[v].rk = group + 1;
			}
			q.push(k);
		}
		tmp = group;
	}
	mice[q.front()].rk = 1;
	for (int i = 0; i<np; i++)
		i == np - 1 ? printf("%d", mice[i].rk) : printf("%d ", mice[i].rk);
	return 0;
}
		
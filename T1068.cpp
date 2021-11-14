#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int a[10005];  // 数
int flag = 0;
vector<int>v;
void DFS(int x, int sum)   //x代表当前是第几个数,y代表当前总和
{
	if (sum == m)
	{
		flag = 1;
		for (int i = 0; i<v.size(); i++)
			i == 0 ? printf("%d", v[i]) : printf(" %d", v[i]);
		return;
	}
	if (sum>m || flag || x == n)
		return;
	v.push_back(a[x]);
	DFS(x + 1, sum + a[x]);
	v.pop_back();
	DFS(x + 1, sum);
}
int main()
{
	cin >> n >> m;
	int s = 0;
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
		s += a[i];
	}
	if (s<m)
	{
		printf("No Solution");
		return 0;
	}
	sort(a, a + n);
	DFS(0, 0);
	if (!flag)
		printf("No Solution");
	return 0;
}

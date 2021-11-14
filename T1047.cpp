#include <iostream>
#include<algorithm>
#include<map>
#include<string>
#include<queue>
using namespace std;
/*��ǰ����һ�������������,��һ�λ�һ�������������ȶ�������*/
priority_queue<string, vector<string>, greater<string> >q[3000];
int main()
{
	int n, m, r, c;
	scanf("%d %d", &n, &m);
	char name[5];
	for (int i = 0; i<n; i++)
	{
		scanf("%s %d", name, &c);
		for (int j = 0; j<c; j++)
		{
			scanf("%d", &r);
			q[r].push(string(name));
		}
	}
	for (int i = 1; i <= m; i++)
	{
		printf("%d %d\n", i, q[i].size());
		while (!q[i].empty())
		{
			printf("%s\n", q[i].top().c_str());
			q[i].pop();
		}
	}
	return 0;
}

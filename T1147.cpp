#include<iostream>
#include<vector>
using namespace std;
int n, m;
int flag;
vector<int>v;
void postTraval(int idx)
{
	if (idx >= m)
		return;
	postTraval(2 * idx + 1);
	postTraval(2 * idx + 2);
	printf("%d%s", v[idx], idx == 0 ? "\n" : " ");
}
int main()
{
	scanf("%d %d", &n, &m);
	v.resize(m);
	for (int i = 0; i<n; i++)
	{
		flag = 1;
		for (int j = 0; j<m; j++)
			scanf("%d", &v[j]);
		flag = v[0]>v[1] ? 1 : -1;
		for (int j = 0; j <= (m - 1) / 2; j++)
		{
			int left = 2 * j + 1, right = 2 * j + 2;
			if ((flag == 1 && v[j]<v[left]) || (flag == -1 && v[j]>v[left]))flag = 0;
			if ((flag == 1 && right<m&&v[j]<v[right]) || (flag == -1 && right<m&&v[j]>v[right])) flag = 0;
		}
		if (flag == 1)
			printf("Max Heap\n");
		else if (flag == -1)
			printf("Min Heap\n");
		else
			printf("Not Heap\n");
		postTraval(0);
	}
	return 0;
}

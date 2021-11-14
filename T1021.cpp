#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
/*�������һ����������������
���۴��ĸ��ڵ㿪ʼ����������ýڵ���Զ�Ľڵ�һ����һ��deepest root,��Ϊ
1. ����ڵ������ͼ���·���ϣ��Ǿ�������Զ�Ľڵ�һ����һ��deepest root,���������ڵ�·���Ͳ����
��·��
2. ����ڵ㲻�����ͼ���·���ϣ��Ǿ�������Զ�Ľڵ�һ����һ��deepest root ,�����������·����
3�����ϣ�����ýڵ���Զ�Ľڵ�һ����һ��deepest root,�ɴˣ���������dfs��������һ����һ��deepest root,
�ڶ��������ڵ㿪ʼ����������������ڵ�*/
using namespace std;
int n, maxheight;
vector<vector<int>>v;  //��vector������ģ����
bool visit[10010];
set<int>s;
vector<int>temp;
void dfs(int node, int height)
{
	if (height>maxheight)
	{
		temp.clear();  // һ��deepest root
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
	v.resize(n + 1);  // ��v���ô�С
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

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;
struct node
{
	int a, b;
};
bool cmp(node x, node y)
{
	return x.a == y.a ? x.b<y.b : x.a<y.a;
}
unordered_map<int, bool>arr;
vector<int>v[10000];
int main()
{
	int n, m, q;
	string a, b;
	cin >> n >> m;
	for (int i = 0; i<m; i++)
	{
		cin >> a >> b;
		if (a.length() == b.length())
		{
			v[abs(stoi(a))].push_back(abs(stoi(b)));
			v[abs(stoi(b))].push_back(abs(stoi(a)));
		}
		arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
	}
	cin >> q;
	for (int i = 0; i<q; i++)
	{
		int c, d;
		cin >> c >> d;
		vector<node>ans;
		for (int j = 0; j<v[abs(c)].size(); j++)
		{
			for (int k = 0; k<v[abs(d)].size(); k++)
			{
				if (v[abs(c)][j] == abs(d) || v[abs(d)][k] == abs(c)) continue;
				if (arr[v[abs(c)][j] * 10000 + v[abs(d)][k]])
					ans.push_back(node{ v[abs(c)][j], v[abs(d)][k] });
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		printf("%d\n", int(ans.size()));
		for (int i = 0; i<ans.size(); i++)
			printf("%04d %04d\n", ans[i].a, ans[i].b);
	}
	return 0;
}

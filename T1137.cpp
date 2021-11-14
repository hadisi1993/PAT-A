#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;
struct node
{
	string sid;
	int gp, gm, gf, g;
};
map<string, int>mp;
vector<node>stu, ans;
bool cmp(node a, node b)
{
	return a.g == b.g ? a.sid<b.sid : a.g>b.g;
}
int main()
{
	int p, m, n, cnt = 1;
	cin >> p >> m >> n;
	for (int i = 0; i<p; i++)
	{
		string id;
		int gp;
		cin >> id >> gp;
		if (gp >= 200)
		{
			stu.push_back({ id, gp, -1, -1, 0 });
			mp[id] = cnt++;
		}
	}

	for (int i = 0; i<m; i++)
	{
		string id;
		int gm;
		cin >> id >> gm;
		if (mp[id])
			stu[mp[id] - 1].gm = gm;
	}
	for (int i = 0; i<n; i++)
	{
		string id;
		int gf;
		cin >> id >> gf;
		if (mp[id])
			stu[mp[id] - 1].gf = gf;
	}
	for (int i = 0; i<stu.size(); i++)
	{
		stu[i].g = stu[i].gm>stu[i].gf ? int(stu[i].gm*0.4 + stu[i].gf*0.6 + 0.5) : stu[i].gf;
		if (stu[i].g >= 60)
			ans.push_back(stu[i]);
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i<ans.size(); i++)
		printf("%s %d %d %d %d\n", ans[i].sid.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
	return 0;
}

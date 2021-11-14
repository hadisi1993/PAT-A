#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct stu
{
	string name;
	int h;
}s[10005];
int cmp(stu a, stu b)
{
	return a.h == b.h ? a.name>b.name:a.h<b.h;
}
int main()
{
	int n, k, num;
	cin >> n >> k;
	num = n / k;
	vector<vector<int>>r(k);
	for (int i = 0; i<n; i++)
	{
		cin >> s[i].name >> s[i].h;
	}
	sort(s, s + n, cmp);
	for (int i = 0; i<k; i++)
	{
		int st = i*num;
		int ed = i == k - 1 ? n - 1 : (i + 1)*num - 1;
		int t = ed;
		while (t >= st)
		{
			r[i].push_back(t);
			t -= 2;
		}
		t = ed - 1;
		while (t >= st)
		{
			r[i].insert(r[i].begin(), t);
			t -= 2;
		}
	}
	for (int i = k - 1; i >= 0; i--)
	{
		cout << s[r[i][0]].name;
		for (int j = 1; j<r[i].size(); j++)
			cout << " " << s[r[i][j]].name;
		cout << endl;
	}
	return 0;
}

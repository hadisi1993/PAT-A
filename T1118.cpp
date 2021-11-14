#include <iostream>
#include<set>
using namespace std;
int k, b, n, q, cnt;
int pre[10005];
set<int>s;
void init()
{
	for (int i = 0; i <= 10000; i++)
		pre[i] = i;
}
int Find(int x)
{
	int index = x;
	while (pre[index] != index)
	{
		index = pre[index];
	}
	return index;
}
void Union(int x, int y)
{
	int xx = Find(x), yy = Find(y);
	if (xx<yy)
		pre[yy] = xx;
	else
		pre[xx] = yy;
	return;
}

int main()
{
	cin >> n;
	init();
	for (int i = 0; i<n; i++)
	{
		cin >> k;
		for (int j = 0; j<k; j++)
		{
			int ss;
			cin >> b;
			if (!j) ss = b;
			s.insert(b);
			Union(ss, b);
		}
	}
	for (int i = 0; i <= 10000; i++)
	{
		if (s.find(i) != s.end() && pre[i] == i)
			cnt++;
	}
	cout << cnt << " " << s.size() << endl;
	cin >> q;
	for (int i = 0; i<q; i++)
	{
		int x, y;
		cin >> x >> y;
		int xx = Find(x), yy = Find(y);
		if (xx == yy)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
struct Property
{
	int id;
	double estate;
	int person;
	double area;
}P[10005];
bool cmp(Property a, Property b)
{
	if (a.person&&b.person)
	{
		if (a.area / a.person != b.area / b.person)
			return a.area / a.person>b.area / b.person;
		else
			return a.id<b.id;
	}
	else
		return a.person>b.person;
}
int vis[10005], pre[10005], n, cnt;
double area[10005], estate[10005];
void init()
{
	for (int i = 0; i<10000; i++)
		pre[i] = i;
}
int find_pre(int x)
{
	if (x == pre[x])
		return x;
	else
		pre[x] = find_pre(pre[x]);
	return pre[x];
}
void Union(int x, int y)
{
	int xx = find_pre(x), yy = find_pre(y);
	if (xx<yy)
		pre[yy] = xx;
	else
		pre[xx] = yy;
}
int main()
{
	init();
	cin >> n;
	int id, f, m, k, ch;
	for (int i = 0; i<n; i++)
	{
		cin >> id >> f >> m;
		vis[id] = 1;
		if (f != -1){
			vis[f] = 1;
			Union(f, id);
		}
		if (m != -1){
			vis[m] = 1;
			Union(m, id);
		}
		cin >> k;
		for (int j = 0; j<k; j++)
		{
			cin >> ch;
			vis[ch] = 1;
			Union(id, ch);
		}
		cin >> estate[id] >> area[id];
	}
	for (int i = 0; i<10000; i++)
	{
		if (vis[i])
		{
			int ans = find_pre(i);
			if (ans == i)
			{
				P[ans].id = i;
				cnt++;
			}
			P[ans].person += 1;
			P[ans].estate += estate[i];
			P[ans].area += area[i];
		}
	}
	sort(P, P + 10000, cmp);
	cout << cnt << endl;
	for (int i = 0; i<10000; i++)
	{
		if (!P[i].person) break;
		printf("%04d %d %.3lf %.3lf\n", P[i].id, P[i].person, P[i].estate / P[i].person, P[i].area / P[i].person);
	}
	return 0;
}

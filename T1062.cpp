#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int T, H;
struct people
{
	int  ID;
	int t, v;
	int level;  // ²ã´Î
	people(){};
	people(int _ID, int _t, int _v) :ID(_ID), t(_t), v(_v)
	{
		if (t<T || v<T)
			level = 0;
		else if (t >= H&&v >= H)
			level = 4;
		else if (t<H&&v >= H)
			level = 3;
		else if (v<H&&t<H&&v >= t)
			level = 2;
		else
			level = 1;
	}
}p[100005];
bool cmp(people a, people b)
{
	if (a.level != b.level)
		return a.level>b.level;
	else
	{
		if ((a.v + a.t) != (b.v + b.t))
			return (a.v + a.t)>(b.v + b.t);
		else
			return a.v == b.v ? a.ID<b.ID : a.v>b.v;
	}
}
int main()
{
	int n, ID, t, v;
	cin >> n >> T >> H;
	int cnt = 0;
	for (int i = 0; i<n; i++)
	{
		scanf("%d %d %d", &ID, &v, &t);
		p[i] = people(ID, t, v);
		if (p[i].level)
			cnt++;
	}
	sort(p, p + n, cmp);
	printf("%d\n", cnt);
	for (int i = 0; i<cnt; i++)
		printf("%08d %d %d\n", p[i].ID, p[i].v, p[i].t);
	return 0;
}

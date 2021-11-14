#include <iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
using namespace std;
void Tolower(string&s)
{
	for (int i = 0; i<s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}
	return;
}
struct ins{
	int R;
	string name;
	double total;
	int num;
}Ins[100005];
map<string, int>m;
bool cmp(ins a, ins b)
{
	if (a.total != b.total)
		return a.total>b.total;
	else if (a.num != b.num)
		return a.num<b.num;
	else
		return a.name<b.name;
}
int n;
int main()
{
	string id, insname;
	double sco;
	cin >> n;
	int cnt = 1;
	for (int i = 0; i<n; i++)
	{
		cin >> id >> sco >> insname;
		Tolower(insname);
		if (id[0] == 'B') sco = sco / 1.5;
		if (id[0] == 'T') sco = sco*1.5;
		if (!m[insname])
			m[insname] = cnt++;
		Ins[m[insname]].name = insname;
		Ins[m[insname]].total += sco;
		Ins[m[insname]].num += 1;
	}
	printf("%d\n", cnt - 1);
	for (int i = 1; i<cnt; i++)
		Ins[i].total = (int)Ins[i].total;
	sort(Ins + 1, Ins + cnt, cmp);
	for (int i = 1; i<cnt; i++)
	{
		if (i == 1 || Ins[i].total != Ins[i - 1].total)
			Ins[i].R = i;
		else
			Ins[i].R = Ins[i - 1].R;
		printf("%d %s %d %d\n", Ins[i].R, Ins[i].name.c_str(), (int)Ins[i].total, Ins[i].num);
	}
	return 0;
}

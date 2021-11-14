#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
struct student{
	LL no;
	int finrank, locrank, loc, score;
};
bool cmp(student a, student b)
{
	return a.score != b.score ? a.score>b.score:a.no<b.no;
}
int main()
{
	int n, m;
	cin >> n;
	vector<student>fin;
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		vector<student>v(m);
		for (int j = 0; j<m; j++)
		{
			scanf("%lld %d", &v[j].no, &v[j].score);
			v[j].loc = i;
		}
		sort(v.begin(), v.end(), cmp);
		v[0].locrank = 1;
		fin.push_back(v[0]);
		for (int j = 1; j<v.size(); j++)
		{
			v[j].locrank = v[j].score == v[j - 1].score ? v[j - 1].locrank : j + 1;
			fin.push_back(v[j]);
		}
	}
	sort(fin.begin(), fin.end(), cmp);
	fin[0].finrank = 1;
	for (int i = 1; i<fin.size(); i++)
		fin[i].finrank = fin[i].score == fin[i - 1].score ? fin[i - 1].finrank : i + 1;
	printf("%d\n", fin.size());
	for (int i = 0; i<fin.size(); i++)
		printf("%013lld %d %d %d\n", fin[i].no, fin[i].finrank, fin[i].loc, fin[i].locrank);
	return 0;
}

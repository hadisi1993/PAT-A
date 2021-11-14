#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct student
{
	string ID, name;
	int score;
};
int flag;
bool cmp(student a, student b)
{
	switch (flag)
	{
	case 1:return a.ID<b.ID; break;
	case 2:return a.name == b.name ? a.ID<b.ID : a.name<b.name; break;
	case 3:return a.score == b.score ? a.ID<b.ID : a.score<b.score; break;
	default:break;
	}
}
int main()
{
	int n;
	cin >> n >> flag;
	vector<student>v(n);
	for (int i = 0; i<n; i++)
		cin >> v[i].ID >> v[i].name >> v[i].score;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i<n; i++)
		cout << v[i].ID << " " << v[i].name << " " << v[i].score << endl;
	return 0;
}

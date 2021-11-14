#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct Student
{
	string name;
	string ID;
	char gender;
	int score;
	bool operator<(const Student&a)const
	{
		return score>a.score;
	}
}M[100005], F[100005];
int main()
{
	int n;
	cin >> n;
	string name, ID;
	char gender;
	int score;
	int mc = 0, fc = 0;
	for (int i = 0; i<n; i++)
	{
		cin >> name >> gender >> ID >> score;
		if (gender == 'M')
			M[mc++] = { name, ID, gender, score };
		else
			F[fc++] = { name, ID, gender, score };
	}
	sort(M, M + mc);
	sort(F, F + fc);    // �֧֧᧲
	fc ? cout << F[0].name << " " << F[0].ID << endl : cout << "Absent" << endl;
	mc ? cout << M[mc - 1].name << " " << M[mc - 1].ID << endl : cout << "Absent" << endl;
	fc&&mc ? cout << F[0].score - M[mc - 1].score << endl : cout << "NA" << endl;
	return 0;
}

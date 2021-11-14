#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct user
{
	string name;
	string pwd;
}U[1005];
int main()
{
	int n;
	cin >> n;
	vector<user>v;
	for (int i = 0; i<n; i++)
	{
		cin >> U[i].name >> U[i].pwd;
		int flag = 0;
		for (int j = 0; j<U[i].pwd.length(); j++)
		{
			switch (U[i].pwd[j])
			{
			case '1':U[i].pwd[j] = '@', flag = 1;; break;
			case '0':U[i].pwd[j] = '%', flag = 1; break;
			case 'l':U[i].pwd[j] = 'L', flag = 1; break;
			case 'O':U[i].pwd[j] = 'o', flag = 1; break;
			default:break;
			}
		}
		if (flag)
			v.push_back(U[i]);
	}
	if (v.size() == 0)
	{
		if (n == 1)
			cout << "There is 1 account and no account is modified" << endl;
		else
			cout << "There are " << n << " accounts and no account is modified" << endl;
	}
	else
	{
		cout << v.size() << endl;
		for (int i = 0; i<v.size(); i++)
			cout << v[i].name << " " << v[i].pwd << endl;
	}
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
int main()
{
	int m;
	cin >> m;
	for (int i = 0; i<m; i++)
	{
		string n;
		cin >> n;
		int k = n.length();
		LL a = stoi(n.substr(0, k / 2)), b = stoi(n.substr(k / 2, k / 2));
		LL c = stoi(n);
		if (!a || !b)
			cout << "No" << endl;
		else
			cout << ((c % (a*b) ? "No" : "Yes")) << endl;
	}
	return 0;
}

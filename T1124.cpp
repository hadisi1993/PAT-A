#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
using namespace std;
set<string>win;
vector<string>ans;
int main()
{
	int m, n, s;
	cin >> m >> n >> s;
	string cad;
	for (int i = 1, cnt = 1; i <= m; i++, cnt++)
	{
		cin >> cad;
		if (i >= s && (cnt - s) % n == 0)
		{
			if (win.find(cad) == win.end())
			{
				win.insert(cad);
				ans.push_back(cad);
			}
			else
				cnt--;
		}

	}
	for (int i = 0; i<ans.size(); i++)
		cout << ans[i] << endl;
	if (!ans.size()) cout << "Keep going..." << endl;
	return 0;
}

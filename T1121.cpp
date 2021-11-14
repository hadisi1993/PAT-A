#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n, m;
vector<int>guest;
map<int, int>couple;
int vis[100005];
int main()
{
	int c1, c2, g;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> c1 >> c2;
		couple[c1 + 1] = c2 + 1;
		couple[c2 + 1] = c1 + 1;
	}
	cin >> m;
	int cnt = m;
	for (int i = 0; i<m; i++)
	{
		cin >> g;
		guest.push_back(g + 1);
	}
	sort(guest.begin(), guest.end());
	for (int i = 0; i<m; i++)
	{
		if (vis[couple[guest[i]]])
		{
			vis[couple[guest[i]]] = 0;
			cnt -= 2;
		}
		else vis[guest[i]] = 1;
	}
	cout << cnt << endl;
	int flag = 1;
	for (int i = 0; i<guest.size(); i++)
	{
		if (vis[guest[i]])
		{
			if (flag)
			{
				flag = 0;
				printf("%05d", guest[i] - 1);
			}
			else
				printf(" %05d", guest[i] - 1);

		}
	}
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;
vector<int>v[205];
bool isClique, isMax;
int book[205];
int nv, ne;
int main()
{
	int e[205][205] = { 0 };
	cin >> nv >> ne;
	int a, b, k, cnt;
	for (int i = 0; i<ne; i++)
	{
		cin >> a >> b;
		e[a][b] = e[b][a] = 1;
	}
	cin >> k;
	for (int i = 0; i<k; i++)
	{
		int val;
		cin >> cnt;
		isClique = isMax = true;
		fill(book, book + 205, 0);
		vector<int>clique;
		for (int j = 0; j<cnt; j++)
		{
			cin >> val;
			clique.push_back(val);
			book[val] = 1;
		}
		for (int j = 0; j<clique.size(); j++)
		{
			for (int k = j + 1; k<clique.size(); k++)
			{
				if (!e[clique[j]][clique[k]])
					isClique = false;
			}
		}
		if (!isClique)
		{
			printf("Not a Clique\n");
			continue;
		}
		for (int j = 1; j <= nv; j++)
		{
			int sum = 0;
			if (!book[j])
			{
				for (int k = 0; k<clique.size(); k++)
				{
					if (e[j][clique[k]])
					{
						sum++;
					}

				}
				if (sum == clique.size()) isMax = false;
			}
		}
		if (!isMax)
		{
			printf("Not Maximal\n");
			continue;
		}
		printf("Yes\n");
	}
	return 0;
}

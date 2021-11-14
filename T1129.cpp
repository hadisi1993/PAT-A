#include<iostream>
#include<set>
using namespace std;
struct node
{
	int idx, val;
	bool operator<(const node&a)const
	{
		return val == a.val ? idx<a.idx : val>a.val;
	}
};
int book[50005];
set<node>s;
int n, k, v;
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &v);
		if (i)
		{
			printf("%d:", v);
			int tmpCnt = 0;
			for (auto it = s.begin(); it != s.end() && tmpCnt<k; it++)
			{
				printf(" %d", it->idx);
				tmpCnt++;
			}
			printf("\n");
		}
		auto it = s.find(node{ v, book[v] });
		if (it != s.end()) s.erase(it);
		book[v]++;
		s.insert(node{ v, book[v] });
	}
	return 0;
}

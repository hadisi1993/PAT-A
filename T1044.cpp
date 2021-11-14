#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;
vector<pair<int, int>>P;
int n;
LL m, sum, total = 0;
int a[100005];    // 商品
int main()
{
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		total += a[i];
	}
	int p1 = 1, p2 = 1;   // 尺取法，开始和结束位置
	sum = a[1];
	while (p2 <= n&&p1 <= n)
	{
		if (sum >= m)
		{
			if (sum == total)
				P.push_back(make_pair(p1, p2));
			else if (sum<total)
			{
				P.clear();
				P.push_back(make_pair(p1, p2));
			}
			total = min(sum, total);
			sum -= a[p1++];
		}
		else
			sum += a[++p2];
	}
	for (int i = 0; i<P.size(); i++)
		printf("%d-%d\n", P[i].first, P[i].second);
	return 0;
}

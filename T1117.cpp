#include <iostream>
#include<algorithm>
using namespace std;
//2 3 6 6 7 7  8 8 9 10
int dis[100005];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		scanf("%d", &dis[i]);
	sort(dis, dis + n);
	int E;
	for (int i = n - 1; i >= 0; i--)
	{
		if (dis[i] == dis[i - 1]) continue;
		if (n - i >= dis[i] - 1)
		{
			E = dis[i] - 1;
			break;
		}
	}
	printf("%d", E);
	return 0;
}

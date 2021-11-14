#include <iostream>
using namespace std;
int k, n, v;
int v1[1005], v2[2005], v3[2005];
int main()
{
	scanf("%d", &k);
	for (int i = 0; i<k; i++)
	{
		int flag = 0;
		fill(v1, v1 + 1005, 0);
		fill(v2, v2 + 2005, 0);
		fill(v3, v3 + 2005, 0);
		scanf("%d", &n);
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &v);
			if (!v1[v] && !v2[v + j] && !v3[n - v + 1 + j])
				v1[v] = v2[v + j] = v3[n - v + 1 + j] = 1;
			else
				flag = 1;
		}
		printf("%s\n", flag == 0 ? "YES" : "NO");
	}
	return 0;
}

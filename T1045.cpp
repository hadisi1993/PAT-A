#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
/*����������Ҳ�Ƚϼ򵥣����ǽ�������ԭ������ѡ��һ��������������������У�Ȼ��������ĳ���
�����о�Ӧ���Ƕ�̬�滮��
����:dp[i][j]: i����ǰ���еĳ��ȣ�j����ڼ�����ϲ������
*/
int dp[10005][205];
map<int, int>s;
int main()
{
	int nc, n, m, v;
	scanf("%d", &nc);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &v);
		s[v] = i;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &v);
		int maxn = 0;
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j];
		}
		for (int j = 1; j <= s[v]; j++)
		{
			maxn = max(maxn, dp[i - 1][j]);
		}
		if (s[v])
			dp[i][s[v]] = maxn + 1;
	}
	int maxn = 0;
	for (int i = 1; i <= n; i++)
		maxn = max(maxn, dp[m][i]);
	printf("%d\n", maxn);
	return 0;
}

#include<iostream>
#include<map>
using namespace std;
/*�������������ȷ������Ҫ�ҵ�һ�����ֵĶ�һ�ް�����
��������map��vis����
*/
map<int, int>m;
int vis[100005];
int main()
{
	int n, v, flag = 0;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &v);
		vis[i] = v;
		m[v]++;
	}
	for (int i = 0; i<n; i++)
	{
		if (m[vis[i]] == 1)
		{
			flag = 1;
			printf("%d\n", vis[i]);
			break;
		}
	}
	if (!flag)
		printf("None\n");
	return 0;
}

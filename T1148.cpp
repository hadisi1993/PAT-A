#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i<n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			vector<int>a(n + 1, 1), liar;
			a[i] = a[j] = -1;
			for (int k = 1; k <= n; k++)
			{
				if (a[abs(v[k])] * v[k]<0)
					liar.push_back(k);
			}
			if (liar.size() == 2 && a[liar[0]] + a[liar[1]] == 0)
			{
				printf("%d %d\n", i, j);
				return 0;
			}
		}
	}
	printf("No Solution\n");
	return 0;
}

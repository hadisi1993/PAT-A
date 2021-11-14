#include <iostream>

using namespace std;
int ranklist[10005], vis[10005], cnt[10005];
bool isPrime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
int n, q, val;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &val);
		ranklist[val] = i;
		cnt[val]++;
	}
	scanf("%d", &q);
	for (int i = 0; i<q; i++)
	{
		scanf("%d", &val);
		if (!cnt[val])
			printf("%04d: Are you kidding?\n", val);
		else
		{
			if (vis[val])
				printf("%04d: Checked\n", val);

			else
			{
				vis[val] = 1;
				if (ranklist[val] == 1)
					printf("%04d: Mystery Award\n", val);
				else
				{
					if (isPrime(ranklist[val]))
						printf("%04d: Minion\n", val);
					else
						printf("%04d: Chocolate\n", val);
				}
			}
		}
	}
	return 0;
}

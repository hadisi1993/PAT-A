#include<iostream>
#include<algorithm>
using namespace std;
int t = 0, n, a[1024], level[1024];
void inorder(int x)
{
	if (x >= n)
		return;
	inorder(2 * x + 1);
	level[x] = a[t++];
	inorder(2 * x + 2);
}
int main()
{
	cin >> n;
	for (int i = 0; i<n; i++)
		scanf("%d", a + i);
	sort(a, a + n);
	inorder(0);
	for (int i = 0; i<t; i++)
		i == 0 ? printf("%d", level[i]) : printf(" %d", level[i]);
}

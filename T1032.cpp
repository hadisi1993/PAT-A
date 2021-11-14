#include<iostream>
#include<algorithm>
//这道题主要是通过静态链表完成
using namespace std;
const int maxn = 1e5 + 5;
struct node
{
	char ch;
	int next;  // 下一个的地址
	int flag;  // 判断第一个单词是不是
}N[maxn];
int main()
{
	int s1, s2, n;
	scanf("%d %d %d", &s1, &s2, &n);
	int cur, next;
	char c;
	for (int i = 0; i<n; i++)
	{
		scanf("%d %c %d", &cur, &c, &next);
		N[cur].ch = c;
		N[cur].next = next;
	}
	for (int i = s1; i != -1; i = N[i].next)
	{
		N[i].flag = 1;
	}
	int index = -1;
	for (int i = s2; i != -1; i = N[i].next)
	if (N[i].flag)
	{
		index = i;
		break;
	}
	index == -1 ? printf("-1\n") : printf("%05d\n", index);
	return 0;
}

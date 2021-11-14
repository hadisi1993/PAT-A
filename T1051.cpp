#include<iostream>
#include<stack>
using namespace std;
/*这道题在做的时候思路不是很清晰，当时大致是用了一个模拟的方法
其实这道题只要考虑两点就足够了
1. 模拟入栈的时候不能超过给定的空间
2. 先前入栈的元素必须按顺序出栈*/
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	stack<int>st;
	for (int i = 0; i<k; i++)
	{
		int p = 1, tmp;
		bool judge = true;
		while (!st.empty())
			st.pop();
		for (int j = 0; j<m; j++)
		{
			scanf("%d", &tmp);
			while (p <= tmp)
			{
				st.push(p);
				if (st.size()>n)
				{
					judge = false;
					break;
				}
				p++;
			}
			if (st.top() != tmp)
			{
				judge = false;
				continue;
			}
			else
				st.pop();
		}
		printf("%s\n", judge ? "YES" : "NO");
	}
	return 0;
}

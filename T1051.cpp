#include<iostream>
#include<stack>
using namespace std;
/*�����������ʱ��˼·���Ǻ���������ʱ����������һ��ģ��ķ���
��ʵ�����ֻҪ����������㹻��
1. ģ����ջ��ʱ���ܳ��������Ŀռ�
2. ��ǰ��ջ��Ԫ�ر��밴˳���ջ*/
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

#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
const int maxn = 1e5 + 5;
/*����⻹�ǽ���ջ�����ã�����ͨջ�Ĺ����ϣ�����⻹������һ�����ܣ�
Ҫ�����ջ��Ԫ�ص���λ��
������ҳ�����V1ector������ģ��ջ,������������г�ʱ
ѧϰ���µ��㷨�Ժ󣬾����÷ֿ��˼�������������
���������ݲ�����100000��sqrt(100000)=316.23,���317�飬ÿ�����316������
1.��һ��block�����¼ÿ���������Ԫ����
2.��table�����¼ÿ��Ԫ�ص�����
3.�����Ĺؼ�������θ���block��table����
1. push:�����������x,x����block[x/316]������У�block[x/316]+=1,table[x]+=1;
2. pop:ջ����Ϊx��block[x/316]-=1,table[x]-=1;
3. peekMedian:���ҵ�(N/2)��Ԫ�ػ���((N+1)/2)��Ԫ��
ʹ�÷ֿ������Ժ󣬴����ɳ�ʱ
�޸���pmd������д����������ջ��Ϊ����������������ʱ�䣬�޸ĺ󲻳�ʱ�����𰸴���
*/
stack<int>S;
int block[320];
int table[maxn];
void pmd()
{
	if (S.empty())
	{
		printf("Invalid\n");
		return;
	}
	else    // ������λ��
	{
		int cnt = S.size();
		int m = cnt % 2 ? (cnt + 1) / 2 : cnt / 2;
		//printf("m:%d\n",m);
		int sum = 0;
		int num = 0;
		while (sum + block[num]<m)
		{
			sum += block[num];
			num++;
		}
		num = num * 316 + 1;
		while (sum + table[num]<m)
		{
			sum += table[num];
			num++;
		}
		printf("%d\n", num);
	}
}
int main()
{
	char str[20];
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		scanf("%s", str);
		if (str[1] == 'o')
		{
			if (S.empty())
			{
				printf("Invalid\n");
			}
			else
			{
				int v = S.top();
				table[v]--;
				block[(v - 1) / 316]--;
				printf("%d\n", v);
				S.pop();
			}

		}
		else if (str[1] == 'u')
		{
			int v;
			scanf("%d", &v);
			S.push(v);
			table[v]++;
			block[(v - 1) / 316] += 1;
		}
		else
		{
			pmd();
		}
	}
	return 0;
}


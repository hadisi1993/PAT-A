#include <iostream>
#include<algorithm>
using namespace std;
//������������ǰ������Ÿ���(����keyֵ�Ĵ�С��)�������ʽͬT1032
//�ڵ�ĵ�ǰ��ַ��keyֵû�иı䣬�ı����next�ڵ��ֵ
//��һ������ʱ������ô���:�Ƚ�ֵ��ȡ������Ȼ�����������Ժ��ٱ���ԭ�������Ҷ�Ӧ��ֵ����ӵ���������
//�ڶ������ʱ��Ҫ��ֱ�Ӱ��б�����������ɣ�����21��
//�����Ŀӵ����ڸ����Ľڵ㲻һ�����������ϣ��п�������Ч�ڵ�
const int maxn = 1e5 + 5;
int v[maxn];   // keyֵ�Ĵ�С
struct node
{
	int key;
	int next;  // ��һ���ĵ�ַ
	node()
	{
		next = -1;
	}
}S[maxn], N[maxn];
int main()
{
	int s1, s2, n;
	scanf("%d %d", &n, &s1);
	int cur, next, value;
	for (int i = 0; i<n; i++)       //������ʼ����
	{
		scanf("%d %d %d", &cur, &value, &next);
		S[cur].key = value;
		S[cur].next = next;
	}
	//���ճ�ʼ��������������
	s2 = -1;
	int cnt = 0;   // �������ϵĽڵ���
	for (int i = s1; i != -1; i = S[i].next)
	{
		cnt++;
		int j;
		int pre = -1;
		for (j = s2; j != -1; j = N[j].next)
		{
			if (S[i].key<N[j].key)
				break;
			pre = j;
		}
		N[i].key = S[i].key;
		if (j>0)             // �������в���
			N[i].next = j;
		if (pre>0)
			N[pre].next = i;
		else
			s2 = i;
	}
	cnt>0 ? printf("%d %05d\n", cnt, s2) : printf("0 -1");
	for (int i = s2; i != -1; i = N[i].next)
		N[i].next == -1 ? printf("%05d %d %d\n", i, N[i].key, N[i].next) : printf("%05d %d %05d\n", i, N[i].key, N[i].next);
	return 0;
}

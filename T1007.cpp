/*�����㷨�������е����������֮��
�㷨��˼���������ģ�
���������һ���Ǵ�һ��������ʼ�ģ����������ڼ���Ĺ�����ֻ����һ��������֮�ͣ����������֮��Ϊ�����ͽ������к͵�ǰ����ӣ�
����������ǰ�����кͣ��Ե�ǰ��Ϊ�������еĵ�һ��Ԫ��
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int INF = -9999999;
int MSS = INF;    //���������֮��
int a[10005];
int main()
{
	int n;
	int SS = 0;  //������֮��
	scanf("%d", &n);
	int flag = 0, P1, P2;
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] >= 0)flag = 1;
	}
	if (!flag)
		printf("0 %d %d", a[0], a[n - 1]);  //���ȫ�Ǹ����Ͱ�Ҫ�����
	else
	{
		int p1, p2;   // ����ָ�룬ָ����������е�һ�������һ��Ԫ��
		for (int i = 0; i<n; i++)
		{
			p2 = i;
			if (SS <= 0)
			{
				p1 = i;
				SS = a[i];
			}
			else
				SS += a[i];
			if (SS>MSS)
			{
				MSS = SS;
				P1 = p1;
				P2 = p2;
			}
		}
		printf("%d %d %d", MSS, a[P1], a[P2]);
		return 0;
	}
}
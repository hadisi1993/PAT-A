/*������˼·��ʵ���ѣ�����ʱû�в���һ�ֺܺúܼ��ķ�����д�����,�ο������ϵĴ����Ժ���д*/
/*�µ�˼·:����һλ������������
1.Ϊѧ���ṹ���������кͷ�������
2.����exist���飬��¼ѧ���Ƿ����(�Ƿ��0),�����0�����¼�ṹ���±�
3.�Ȱ������������������Ժ����¸�������(��¼���е����),Ȼ������ṹ�����飬��ѡ����õ�����
*/
#include<iostream>
#include<algorithm>
using namespace std;
int flag = 0;
int exist[1000000];
struct stu
{
	int id, best;   // ��λ��ѧ��,��õ�����,������������
	int score[4], rank[4];  // ���ſεķ�����ע��������ƽ������ȡ����
}s[2005];
bool cmp(stu a, stu b)    //������д�����Է�������
{
	return a.score[flag]>b.score[flag];
}
char kw[] = { 'A', 'C', 'M', 'E' };
int main()
{
	int n, m, id;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++)
	{
		scanf("%d %d %d %d", &s[i].id, &s[i].score[1], &s[i].score[2], &s[i].score[3]);
		s[i].score[0] = (s[i].score[1] + s[i].score[2] + s[i].score[3]) / 3.0 + 0.5;  // ����ƽ���֣���������
		s[i].best = 10000;
	}
	for (flag = 0; flag<4; flag++)
	{
		sort(s, s + n, cmp);
		s[0].rank[flag] = 1;
		for (int i = 1; i<n; i++)
		{
			s[i].rank[flag] = i + 1;
			if (s[i - 1].score[flag] == s[i].score[flag])
			{
				s[i].rank[flag] = s[i - 1].rank[flag];
			}
		}

	}
	for (int i = 0; i<n; i++)
	{
		exist[s[i].id] = i + 1;
		s[i].best = 0;
		int minn = s[i].rank[0];
		for (int j = 1; j<4; j++)
		{
			if (minn>s[i].rank[j])
			{
				minn = s[i].rank[j];
				s[i].best = j;
			}
		}
	}
	for (int i = 0; i<m; i++)  // �����������
	{
		scanf("%d", &id);
		if (exist[id])
		{
			int temp = s[exist[id] - 1].best;
			printf("%d %c\n", s[exist[id] - 1].rank[temp], kw[temp]);
		}
		else
		{
			printf("N/A\n");
		}
	}
	return 0;
}

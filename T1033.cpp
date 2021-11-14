#include<iostream>
#include<algorithm>
using namespace std;
/*ԭ��:���˵ļ���վ�����
1. ������վ�ṹ�尴���ͼ�����
2. ѡ�����վ,����վ������������ʣ������
3. �ڳ����˶���Χ�ڣ����ܲ����ҵ������˵ļ���վ(�������յ�)��������ҵ�����͵��պ��ܿ����Ǹ�����վ������ȫ������
4. �����˶��Ĺ����У������˶���Χ�ڵļ���վ�ĺ�����
5. ������վ�ṹ�尴��������,�ж��ܲ��ܵ���
6. ����ÿ������վ�������������Զ�ܵ���ľ���
*/
double sum = 0;  // �ط���
double cap, dist, per;
int n;
struct station
{
	int flag;   // �Ƿ��ܹ�����
	double price;
	double distance; //��ǰ����
	double remain;  // ��ʣ�µ�����
	double m_distance;   // ��������Զ�ܹ�����ľ���
}S[505];
bool cmp1(station a, station b)
{
	return a.price<b.price;
}
bool cmp2(station a, station b)
{
	return a.distance<b.distance;
}
int main()
{
	cin >> cap >> dist >> per >> n;
	for (int i = 0; i<n; i++)
	{
		scanf("%lf %lf", &S[i].price, &S[i].distance);
		S[i].m_distance = S[i].distance + per*cap <= dist ? S[i].distance + per*cap : dist;  // ������Զ�ܵ���ľ���
	}
	sort(S, S + n, cmp1);  // ���ռ۸�����
	for (int i = 0; i<n; i++)
	{
		double add = 0;
		int index = 0;  // �����������ļ���վ
		int flag = 0;  //����������վ�Ƿ����
		for (int j = 0; j<i; j++)
		{
			if (S[j].distance>S[i].distance&&S[i].m_distance >= S[j].distance)
			{
				if (index == 0 || S[j].distance<S[index].distance)
				{
					index = j;
					flag = 1;
				}
			}
		}
		if (S[i].remain*per + S[i].distance<dist)  // Ŀǰ���Ϳ������յ�
		{
			if (flag)
				add = S[i].price*((S[index].distance - S[i].distance) / per - S[i].remain);  // Ҫ�ӵ���Ǯ
			else
			{
				if (S[i].m_distance<dist)  // �յ㲻�ٿɴﷶΧ�ڣ��Ǽ����;�����
					add = (cap - S[i].remain)*S[i].price;
				else
					add = ((dist - S[i].distance) / per)*S[i].price;
			}
		}
		for (int j = 0; j<n; j++)
		{
			if (S[j].distance>S[i].distance&&S[i].m_distance >= S[j].distance)
			{
				S[j].remain = cap - (S[j].distance - S[i].distance) / per;  // ����ʣ�µ�����
			}
		}
		// cout<<add<<endl;
		sum += add;    //���·���
	}
	sort(S, S + n, cmp2);  // ���վ�������
	for (int i = 0; i<n; i++)
	{
		if (S[i].distance == 0)
			S[i].flag = 1;
		if (S[i].flag)
		{
			for (int j = 0; j<n; j++)
			{
				if (S[j].distance <= S[i].m_distance)
					S[j].flag = 1;
			}
		}
	}
	double maxdist = 0;
	for (int i = 0; i<n; i++)
	{
		if (S[i].flag)
			maxdist = max(maxdist, S[i].m_distance);
	}
	if (maxdist == dist)
		printf("%.2f\n", sum);
	else
		printf("The maximum travel distance = %.2f\n", maxdist);
	return 0;
}


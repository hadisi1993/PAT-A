#include<iostream>
#include<algorithm>
using namespace std;
/*��������������ϴ�ƣ�ÿһ��ϴ��Ҫ����54�����֣�ÿ�����ִ�����ǰ�����ƶ���
���µ�λ��
����
1. ��һ���ṹ���ʾһ����
2. �ƵĽṹ����:��ɫ���ƺţ���ǰλ��
3. ÿ��������λ�ã��ͽ���ǰλ�����룬Ȼ����������
4. ������������������*/
struct card
{
	char ty;  // ����
	int order; // ���
	int pos;   // λ��
	card(){}
	card(char _t, int _order, int _pos) :ty(_t), order(_order), pos(_pos){}
	bool operator <(const card&a)const
	{
		return pos<a.pos;
	}
}Card[55];
int tmp[55];
char s[] = { 'S', 'H', 'C', 'D', 'J' };
int main()
{
	for (int i = 0; i <= 53; i++)
	{
		Card[i] = card(s[i / 13], i % 13 + 1, i + 1);
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i<54; i++)
		scanf("%d", &tmp[i]);
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j <= 53; j++)
		{
			Card[j].pos = tmp[j];
		}
		sort(Card, Card + 54);
	}
	printf("%c%d", Card[0].ty, Card[0].order);
	for (int i = 1; i<54; i++)
		printf(" %c%d", Card[i].ty, Card[i].order);
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
/*�����Ӧ����һ��̰���⣬Ҫ����������棬�����������ü�ֵ�����Ʒ���ؾ�����Ĵ���
������һЩ�涨
1.�����Ż�ȯ��Ӧ�����ڼ�ֵΪ������Ʒ�Ҽ�ֵԽ�����Ʒ��
2.�����Ż�ȯ��Ӧ�����ڼ�ֵΪ�����Ҽ�ֵС����Ʒ��
3.�Ż�ȯ����Ʒ��ͬ������
�������
1.�ȼ�������ȫΪ����
2.�ټ�������ȫΪ����*/
int main()
{
	LL nc, np, sum = 0;
	LL c[100005], p[100005];
	scanf("%lld", &nc);
	for (int i = 0; i<nc; i++)
		scanf("%lld", &c[i]);
	scanf("%lld", &np);
	for (int i = 0; i<np; i++)
		scanf("%lld", &p[i]);
	sort(c, c + nc);
	sort(p, p + np);
	int p1 = 0;
	while (p[p1] * c[p1]>0 && p[p1]<0)
	{
		sum += p[p1] * c[p1];
		p1++;
	}
	// printf("%d\n",p1);
	//printf("%lld\n",sum);
	int p21 = nc - 1, p22 = np - 1;
	while (p21 >= p1&&p22 >= p1&&c[p21] * p[p22]>0)
	{
		sum += c[p21] * p[p22];
		p21--, p22--;
	}
	printf("%lld\n", sum);
	return 0;
}


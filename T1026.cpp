#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
/*��������ǰ������1014��1017����񣬶���ģ���⣬����Ҫ���Ӹ���һ�㣬��Ϊ����һ��VIP��
�����ڱ���ƹ��������ʱ��1.Ҫ��ƹ�������ǲ���VIP��2.Ҫ����������û��VIP�ͻ�
��Ŀ�����̴�������
1.������������������ǲ��ǿյģ��пյ�
1.1 ��VIP�������Ƚϵ�ǰʱ��͵�һ���ȴ���Ա�ĵ���ʱ�䣬�����������
1.2 VIP���������Ҷ������Ƿ���VIP��Ա���еĻ��Ƚϵ�ǰʱ����䵽��ʱ�䣬����������䣬�����ڷ�VIP��Ա��
����
2.������ǿյ������ʱ��-1
3.��ǰʱ��+1
����ؼ�:VIP��Ա�ͷ�VIP��Ա��δ洢
�ҵ��뷨��:������Ա��һ������洢��VIP��Ա����һ�����ȶ��д洢������Ա��ַ����Ա�ṹ������һ������
�����Ա�Ƿ񱻷��������������������Աʱ���������Ѿ��������VIP��Ա
�������֣�����ԭ�뷨��������еľ�Ҫ�ǽڵ�ĵ�ַ�����������޸����ݡ�����̫�����ˣ����Ի���һ���뷨
�����vip����ֱ���ڵ�ǰ�û�����ҵ�һ�����ܵ�vip�û��ȿ�
ǰ�潻�����Σ��õ�24�֣�˵�������в��Եĵط������ֿ���һ����Ŀ��������һ���ط�û�п��ǣ�����һ��
vip�û�������ݣ����е������ǿյģ�����Ӧ�û�����ѡ��vip��,�������ֶ���4��
*/
using namespace std;
int cutime = 0; // ��ǰʱ��
struct baller
{
	int atime; // ����ʱ��
	int ptime; // �˶�ʱ��
	int vip; //�ǲ���vip
	int flag; // �Ƿ��Ѿ�������
	int stime; // ��ʼ�����ʱ��
	bool operator <(const baller&b)const
	{
		return atime<b.atime;
	}
}b[10005];
struct table
{
	int remain;
	int vip; // �ǲ���vip��
	int sev; // ���������
	int id;
	table()
	{
		remain = 0;
		vip = 0;
		sev = 0;
	}
}Table[200];
int str2time(char*str)
{
	int h, m, s;
	sscanf(str, "%d:%d:%d", &h, &m, &s);
	return 3600 * h + 60 * m + s;
}
void print(int t1, int t2)  // ʱ���תʱ��
{
	int h, m, s;
	h = t1 / 3600;
	m = (t1 - 3600 * h) / 60;
	s = t1 % 60;
	printf("%02d:%02d:%02d ", h, m, s);
	h = t2 / 3600;
	m = (t2 - 3600 * h) / 60;
	s = t2 % 60;
	printf("%02d:%02d:%02d %.0f\n", h, m, s, round((float)(t2 - t1) / 60));
}
bool cmp(baller a, baller b)
{
	return a.stime<b.stime;
}
int main()
{
	char str[20];
	int t, v; // ����ʱ����ǲ���vip
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		scanf("%s %d %d", str, &t, &v);
		b[i].atime = str2time(str);
		b[i].ptime = t * 60;
		b[i].vip = v;
	}
	int cnt, vcnt; // ��������vip������
	scanf("%d %d", &cnt, &vcnt);
	int w;
	for (int i = 0; i<vcnt; i++)
	{
		scanf("%d", &w);
		Table[w].vip = 1;
	}
	cutime = 8 * 3600;
	sort(b, b + n);
	int ab = 0;  // �������˵���
	while (ab<n&&cutime<21 * 3600)
	{
		for (int i = 1; i <= cnt; i++)    //���ȱ���vip������vip��Ա���
		{
			if (Table[i].vip&&ab<n&&!Table[i].remain)     // ��vip��
			{
				int p = ab;    // �ӵ�ǰ�û���ʼ������vip�û�
				while (p<n)
				{
					if (b[p].vip&&!b[p].flag&&cutime >= b[p].atime)   // ��ǰ��������vip�˿Ϳ��Է���
						break;
					p++;
				}
				if (p<n)      //�ҵ��˿��Է����vip�ͻ�
				{
					b[p].stime = cutime;  // ����ǰʱ���Ϊ��ʼ�����ʱ��
					Table[i].remain = b[p].ptime>7200 ? 7200 : b[p].ptime;   //�����Ȳ���ȥ��ǰ�����1�룬�ٴα���ʱͳһ��
					Table[i].sev += 1;
					b[p].flag = 1;
				}
			}
		}
		for (int i = 1; i <= cnt; i++)//�Ѿ�û��vip��ԱҪȥvip����
		{
			if (!Table[i].remain&&ab<n)
			{
				while (b[ab].flag)    //������ǰ���б��������vip�û�
					ab++;
				if (cutime >= b[ab].atime&&ab<n)
				{
					Table[i].remain = b[ab].ptime>7200 ? 7200 : b[ab].ptime - 1;
					Table[i].sev += 1;
					b[ab].stime = cutime;
					ab++;
				}
			}
			else if (Table[i].remain>0)
			{
				Table[i].remain -= 1;
			}
		}
		cutime++;
	}
	sort(b, b + n, cmp);
	for (int i = 0; i<n; i++)
	{
		if (b[i].stime)
			print(b[i].atime, b[i].stime);
	}
	for (int i = 1; i <= cnt; i++)
	{
		if (i>1) printf(" ");
		printf("%d", Table[i].sev);
	}

	return 0;
}

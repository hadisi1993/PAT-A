#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
/*�����������˼�벻һ���ĵط����ڣ������ǰ���ʱ������ķ����ж�ҵ���Ƿ���ɣ�������û��remaintime�ĸ���
���Ľ��˼·��,Ϊÿ����������һ��poptime���Ա��ڼ�����������Ӧ��ѡ���ĸ�����ȥ����Ȼ��������һ��endtime
��¼ÿ���˽��������ʱ�䣬����540����¼sorry
����:�������ִ�ģ���⣬���ݽṹ������ʮ����Ҫ
*/
struct node{    // ���ڽṹ��
	int poptime, endtime;
	queue<int>q;
};
int main()
{
	int n, m, cnt, query, index = 1;
	scanf("%d %d %d %d", &n, &m, &cnt, &query);
	vector<int>time(cnt + 1), res(cnt + 1);
	for (int i = 1; i <= cnt; i++)
		scanf("%d", &time[i]);
	vector<node>windows(n + 1);
	vector<bool>sorry(cnt + 1, false);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (index <= cnt)           // ���˿�ָ���������
			{
				windows[j].q.push(time[index]);
				if (windows[j].endtime >= 540)
					sorry[index] = true;
				windows[j].endtime += time[index];
				if (i == 1)
					windows[j].poptime = windows[j].endtime;
				res[index] = windows[j].endtime;
				index++;
			}
		}
	}
	while (index <= cnt)
	{
		int tempmin = windows[1].poptime, tempwin = 1;  //Ϊʣ�µĹ˿Ͳ��Ҵ���
		for (int i = 2; i <= n; i++)
		{
			if (windows[i].poptime<tempmin)
			{
				tempwin = i;
				tempmin = windows[i].poptime;
			}
		}
		windows[tempwin].q.pop();
		windows[tempwin].q.push(time[index]);
		windows[tempwin].poptime += windows[tempwin].q.front();
		if (windows[tempwin].endtime >= 540)
			sorry[index] = true;
		windows[tempwin].endtime += time[index];
		res[index] += windows[tempwin].endtime;
		index++;
	}
	for (int i = 1; i <= query; i++)
	{
		int q, minute;
		scanf("%d", &q);
		if (sorry[q])
			printf("Sorry\n");
		else
		{
			minute = res[q];
			printf("%02d:%02d\n", (minute + 480) / 60, (minute + 480) % 60);
		}
	}
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
/*这道题大神和我思想不一样的地方在于，她不是按照时间遍历的方法判断业务是否完成，所以它没有remaintime的概念
她的解决思路是,为每个窗口设立一个poptime，以便于计算黄线外的人应该选择哪个窗口去服务，然后在设置一个endtime
记录每个人结束服务的时间，超过540即记录sorry
感想:对于这种大模拟题，数据结构的设立十分重要
*/
struct node{    // 窗口结构体
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
			if (index <= cnt)           // 将顾客指派入黄线中
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
		int tempmin = windows[1].poptime, tempwin = 1;  //为剩下的顾客查找窗口
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

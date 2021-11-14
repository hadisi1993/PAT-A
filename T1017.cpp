#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
/*这道题大神的思想使用优先队列来做这道题，因为这道题的排序比较简单
如果最早结束服务的窗口时间早于顾客到达的时间，那么不需要等待，否则
用队首元素保存的时间减去顾客到达的时间代表等待时间*/
const int maxn = 10005;
struct person
{
	int com, time;
	bool operator<(const person&a)const
	{
		return com<a.com;
	}
}p[maxn];
int n, k, cnt, total;
int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		int hh, ss, mm, tt;
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &tt);
		int sum = hh * 3600 + mm * 60 + ss;
		if (sum>61200) continue;
		p[++cnt].time = tt * 60;
		p[cnt].com = sum;
	}
	sort(p + 1, p + cnt + 1);
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 1; i <= k; i++)
		q.push(28800);
	for (int i = 1; i <= cnt; i++)
	{
		if (q.top() <= p[i].com)
		{
			q.push(p[i].com + p[i].time);
			q.pop();  // 换人
		}
		else
		{
			total += q.top() - p[i].com;
			q.push(q.top() + p[i].time);
			q.pop();
		}
	}
	(!cnt) ? printf("0.0\n") : printf("%.1f\n", ((double)total / 60.0) / (double)cnt);
	return 0;
}

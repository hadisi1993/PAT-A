#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
/*这道题第一遍是在是写的太丑了，用了好多远了没必要用上的东西*/
using namespace std;
/*策略，先按照姓名排序,然后再按照时间排序，然后再在排好序的
序列中遍历，找姓名相同而且符合on-line状态的对话
为计算时间方便，在结构体中添加month,day,hour,minute;
*/
struct record
{
	string name;
	int time;
	int state;  // 状态
	int month, day, hour, minute;
};
int toll[25] = { 0 };  // 话费数组
bool cmp(record a, record b)
{
	return (a.name == b.name) ? (a.time<b.time) : (a.name<b.name);
}
double billFromZero(record call)
{
	double total = toll[call.hour] * call.minute + toll[24] * 60 * call.day;
	for (int i = 0; i<call.hour; i++)
	{
		total += toll[i] * 60;
	}
	return total / 100.0;
}
int n;

int main()
{
	//freopen("input.txt","r",stdin);
	for (int i = 0; i<24; i++)
	{
		scanf("%d", &toll[i]);
		toll[24] += toll[i];    //为计算方便，在toll[24]中存储一天的通话费用/60;
	}
	scanf("%d", &n);
	vector<record>R(n);
	for (int i = 0; i<n; i++)
	{
		cin >> R[i].name;
		scanf("%d:%d:%d:%d", &R[i].month, &R[i].day, &R[i].hour, &R[i].minute);
		R[i].time = R[i].day * 1440 + R[i].hour * 60 + R[i].minute;
		string temp;
		cin >> temp;
		R[i].state = (temp == "on-line") ? 1 : 0;
	}
	sort(R.begin(), R.end(), cmp);
	map<string, vector<record> >custom;
	for (int i = 1; i<n; i++)
	{
		if (R[i].name == R[i - 1].name&&R[i - 1].state == 1 && R[i].state == 0)
		{
			custom[R[i - 1].name].push_back(R[i - 1]);
			custom[R[i].name].push_back(R[i]);
		}
	}
	for (auto it : custom)  //开始计算时间
	{
		cout << it.first;
		vector<record>temp = it.second;
		printf(" %02d\n", temp[0].month);
		double total = 0.0;
		for (int i = 1; i<temp.size(); i += 2)
		{
			double m = billFromZero(temp[i]) - billFromZero(temp[i - 1]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", \
				temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, m);
			total += m;
		}
		printf("Total amount: $%.2f\n", total);
	}
	return 0;
}

/*这道题的思路其实不难，但当时没有采用一种很好很简便的方法来写这道题,参考了网上的代码以后，重写*/
/*新的思路:网上一位大神做法如下
1.为学生结构体设置排行和分数数组
2.设立exist数组，记录学生是否存在(是否非0),如果非0，则记录结构体下标
3.先按分数排序，排序完了以后重新更正排名(记录并列的情况),然后遍历结构体数组，挑选出最好的排名
*/
#include<iostream>
#include<algorithm>
using namespace std;
int flag = 0;
int exist[1000000];
struct stu
{
	int id, best;   // 六位的学号,最好的排名,最好排名的序号
	int score[4], rank[4];  // 四门课的分数，注意这道题的平均分是取整的
}s[2005];
bool cmp(stu a, stu b)    //这样的写法可以方便排序
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
		s[i].score[0] = (s[i].score[1] + s[i].score[2] + s[i].score[3]) / 3.0 + 0.5;  // 计算平均分，四舍五入
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
	for (int i = 0; i<m; i++)  // 查找最佳排名
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

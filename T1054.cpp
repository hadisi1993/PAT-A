#include<iostream>
#include<algorithm>
#include<string>
#include<map>
/*����⿴��ȥ��һ��������������
����˼·:�����е������������ڣ����ճ��ֵĴ�����ɸѡ�����ִ���������
*/
using namespace std;
int main()
{
	map<string, int>mt;
	int m, n;
	cin >> m >> n;
	int i = 0;
	string str;
	while (i<m*n)
	{
		cin >> str;
		mt[str]++;
		i++;
	}
	map<string, int>::iterator it;
	int maxn = 0;
	for (it = mt.begin(); it != mt.end(); it++)
	{
		if (it->second>maxn)
		{
			maxn = it->second;
			str = it->first;
		}
	}
	cout << str << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
/*���������ĵط������������˻��ĵ����ʣ����˴���������Ĺ���*/
using namespace std;
string s;
void add(string t)
{
	int len = t.length(), ram = 0;
	for (int i = 0; i<len; i++)
	{
		s[i] = s[i] + t[i] + ram - '0';
		ram = 0;
		if (s[i]>'9')
		{
			s[i] = s[i] - 10;
			ram = 1;
		}
	}
	if (ram) s += '1';
	reverse(s.begin(), s.end());
}
int main()
{
	int cnt, i;
	cin >> s >> cnt;
	for (i = 0; i <= cnt; i++)
	{
		string t = s;
		reverse(t.begin(), t.end());
		if (t == s || i == cnt)
			break;
		add(t);
	}
	cout << s << endl << i;
}

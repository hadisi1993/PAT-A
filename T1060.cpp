#include<iostream>
#include<string>
using namespace std;
string str = "*10^";
string change(string s, int n)
{
	string res = "0.";
	int len = s.length(), cnt = 0;
	int pos = 0;
	for (int i = 0; i<len; i++)   // 寻找开始位置
	if (s[i] == '0' || s[i] == '.')
		pos++;
	else
		break;
	int dp = s.find('.') == -1 ? len : s.find('.');  // 点的位置
	for (int i = pos; cnt<n&&i<len; i++)
	{
		if (s[i] == '.')
			continue;
		else
		{
			cnt++;
			res += s[i];
		}
	}
	if (res.length()<n + 2)
	{
		int len2 = n + 2 - res.length();
		res.insert(res.length(), len2, '0');
	}
	res = res + str;
	if (pos == len)
		res += '0';
	else
		res += dp - pos>0 ? to_string(dp - pos) : to_string(dp - pos + 1);
	return res;
}
int main()
{
	int n;
	string str1, str2;
	cin >> n >> str1 >> str2;
	if (change(str1, n) == change(str2, n))
		cout << "YES " << change(str1, n);
	else
		cout << "NO " << change(str1, n) << " " << change(str2, n) << endl;
	return 0;
}

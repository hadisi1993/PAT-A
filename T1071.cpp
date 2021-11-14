#include <iostream>
#include<string>
#include<map>
#include<cctype>
#include<sstream>
using namespace std;
map<string, int>m;  // 用来统计
void change(string&str)
{
	for (int i = 0; i<str.length(); i++)
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
		if (!isalnum(str[i]))
		{
			str[i] = ' ';
		}
	}
}
int main()
{
	stringstream ss;
	string str, s;
	getline(cin, str);
	change(str);
	ss << str;
	while (ss >> s)
	{
		m[s]++;
	}
	int maxn = 0;
	string ans = "";
	for (auto it = m.begin(); it != m.end(); it++)
	{
		if (it->second>maxn)
		{
			ans = it->first;
			maxn = it->second;
		}
	}
	cout << ans << " " << maxn << endl;
	return 0;
}

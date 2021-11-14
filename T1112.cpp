#include <iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
bool NoSureStruck[1000];
set<char>s;
map<char, bool>m;
string str;
int k;
int main()
{
	cin >> k;
	cin >> str;
	char pre = '#';
	str = str + '#';
	int cnt = 1;
	for (int i = 0; i<str.length(); i++)
	{
		if (str[i] == pre) cnt++;
		else
		{
			if (cnt%k != 0) NoSureStruck[pre] = true;
			cnt = 1;
		}
		if (i != str.length() - 1) m[str[i]] = (cnt%k == 0);
		pre = str[i];
	}
	for (int i = 0; i<str.length(); i++)
	if (NoSureStruck[str[i]]) m[str[i]] = 0;
	for (int i = 0; i<str.length() - 1; i++)
	{
		if (m[str[i]] && s.find(str[i]) == s.end())
		{
			printf("%c", str[i]);
			s.insert(str[i]);
		}
	}
	printf("\n");
	for (int i = 0; i<str.length() - 1; i++)
	{
		printf("%c", str[i]);
		if (m[str[i]])
			i += (k - 1);
	}
	return 0;
}

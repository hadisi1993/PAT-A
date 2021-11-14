#include <iostream>
#include<string>
using namespace std;
/*字符串的乘法,一种比较简单的做法*/
string s, double_s;
int a[10];  // 记录出现的位数
int main()
{
	cin >> s;
	int len = s.length(), ram = 0, digit;
	for (int i = len - 1; i >= 0; i--)
	{
		a[s[i] - '0']++;
		digit = (2 * (s[i] - '0') + ram) % 10;
		ram = (2 * (s[i] - '0') + ram) / 10;
		double_s.insert(double_s.begin(), 1, '0' + digit);
		a[digit]--;
	}
	if (ram)
	{
		double_s.insert(double_s.begin(), 1, '0' + ram);
		a[ram]--;
	}
	int flag = 1;
	for (int i = 0; i<10; i++)
	if (a[i]) flag = 0;
	cout << (flag ? "Yes" : "No") << endl;
	cout << double_s << endl;
	return 0;
}

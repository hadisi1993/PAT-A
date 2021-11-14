#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
string BigNumberAdd(string a, string b)
{
	string tmpStr = "";
	int ram = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		tmpStr = (char)((a[i] + b[i] - 2 * '0' + ram) % 10 + '0') + tmpStr;
		ram = ((a[i] + b[i] - 2 * '0' + ram) / 10);
	}
	if (ram)
		tmpStr = (char)(ram + '0') + tmpStr;
	return tmpStr;
}
int main()
{
	string num, tmpStr;
	cin >> num;
	int i, flag = 0;
	for (i = 0; i<10; i++)
	{
		string tmpStr = num;
		reverse(tmpStr.begin(), tmpStr.end());
		if (tmpStr == num)
		{
			flag = 1;
			printf("%s is a palindromic number.", num.c_str());
			break;
		}
		printf("%s + %s = ", num.c_str(), tmpStr.c_str());
		num = BigNumberAdd(num, tmpStr);
		printf("%s\n", num.c_str());
	}
	if (!flag)
		printf("Not found in 10 iterations.");
	return 0;
}

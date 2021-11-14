#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool cmp(char a, char b)
{
	return b<a;
}
int main()
{
	string num;
	int a, b;
	cin >> num;
	if (num.length()<4)
		num.insert(0, 4 - num.length(), '0');
	while (1)
	{
		sort(num.begin(), num.end(), cmp);
		a = stoi(num);
		sort(num.begin(), num.end());
		b = stoi(num);
		printf("%04d - %04d = %04d\n", a, b, a - b);
		if (a - b == 6174 || a - b == 0)
			break;
		else
			num = to_string(a - b);
		if (num.length()<4)
			num.insert(0, 4 - num.length(), '0');
	}
	return 0;
}

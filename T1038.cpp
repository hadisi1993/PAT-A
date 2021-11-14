#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*看了大神的想法，原来改变两个字符串的相加顺序，再比较就好了*/
string num[10005];
bool cmp(string x, string y)     //比较函数
{
	return x + y<y + x;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> num[i];
	sort(num, num + n, cmp);
	int index = n;
	for (int i = 0; i<n; i++)
	{
		if (stoi(num[i])>0)
		{
			index = i + 1;
			cout << stoi(num[i]);
			break;
		}

	}
	for (int i = index; i<n; i++)
		cout << num[i];
	if (index == n)
		cout << 0 << endl;
	return 0;
}

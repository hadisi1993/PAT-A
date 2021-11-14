#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int n;
	string d;
	cin >> d >> n;
	string str = "";
	if (n == 1)
	{
		cout << d << endl;
		return 0;
	}
	for (int i = 1; i<n; i++)
	{
		str = "";
		str += d[0];
		int cnt = 1;
		for (int j = 1; j<d.length(); j++)
		{
			if (d[j - 1] == d[j])
				cnt++;
			else
			{
				str += to_string(cnt);
				str += d[j];
				cnt = 1;
			}
		}
		str += to_string(cnt);
		d = str;
	}
	cout << str << endl;
	return 0;
}

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int pos = str.find('E');
	string num = str.substr(1, pos - 1);
	int exp = stoi(str.substr(pos + 1, str.length() - pos));
	if (exp>0)
	{
		for (int i = 0; i<exp; i++)
		{
			int pos = num.find('.');
			if (pos == num.length() - 1)
				num += '0';
			swap(num[pos], num[pos + 1]);
		}
		if (num[num.length() - 1] == '.')
			num = num.substr(0, num.length() - 1);
	}
	else
	{
		for (int i = 0; i<-1 * exp; i++)
		{
			int pos = num.find('.');
			if (pos == 0)
				num = '0' + num, pos = 1;
			swap(num[pos], num[pos - 1]);
		}
		if (num[0] == '.')
			num = '0' + num;
	}
	if (str[0] == '-')
		cout << str[0];
	cout << num << endl;
	//    cout<<sig<<str<<endl;
	return 0;
}

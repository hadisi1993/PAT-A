#include <iostream>
#include<string>
using namespace std;
/*���ַ���������,����Ҫע��ʱ�������*/
int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	for (int i = 0; i<str2.length(); i++)
	{
		int pos = str1.find(str2[i]);
		while (pos != string::npos)
		{
			str1.erase(pos, 1);      //ɾ���ַ���
			pos = str1.find(str2[i]);
		}
	}
	cout << str1 << endl;
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
/*�������ִ�,����������ʾ����
�����϶�Ҫ�ö�̬�滮��
��̬�滮����:dp[][]*/
int dp[1005][1005];  // ״̬ת�Ʒ���
int main()
{
	string str;
	getline(cin, str);
	int len = str.length();  // �ַ�������
	int maxlen = -1;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j + i <= len; j++)   // jΪ��ʼλ��
		{
			if (i>2) // ���Ĵ�������2����
			{
				if (str[j] == str[j + i - 1] && dp[j + 1][j + i - 2])
				{
					dp[j][j + i - 1] = 1;
					maxlen = i;
				}
				else
					dp[j][j + i - 1] = 0;
			}
			else
			{
				if (str[j] == str[j + i - 1])
				{
					dp[j][j + i - 1] = 1;
					maxlen = i;
				}
				else
					dp[j][j + i - 1] = 0;

			}
		}
	}
	cout << maxlen << endl;
	return 0;
}

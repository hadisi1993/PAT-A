#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int pos = 0; //�������ڵ�λ��
	int time = 0;
	for (int i = 0; i<n; i++)
	{
		int loc;  //Ҫ���ڵ�λ��
		cin >> loc;
		time += loc>pos ? 6 * (loc - pos) : 4 * (pos - loc);
		pos = loc; //���µ���λ��
	}
	time += 5 * n;
	cout << time << endl;
	return 0;
}

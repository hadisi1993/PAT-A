#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	float a, b, c;
	float result = 1;
	for (int i = 0; i<3; i++)
	{
		scanf("%f %f %f", &a, &b, &c);
		float tmp = max(max(a, b), c);              //�����Ψһ���ӵĵط����ڱȽ��������Ĵ�С����Ӧ
		printf("%c ", tmp == max(a, b) ? (tmp == a ? 'W' : 'T') : 'L');
		result *= tmp;
	}
	printf("%.2f", (result*0.65 - 1) * 2);
	return 0;
}

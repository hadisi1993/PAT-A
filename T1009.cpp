/*����ʽ�˷����ҵ��뷨�������鱣�����ʽ��ϵ�����±�����ʾָ��*/
#include<iostream>
#include<algorithm>
using namespace std;
float poly1[1005];
float poly2[1005];
float poly3[2005];
int main()
{
	int n1, n2, exp;
	int maxterm1 = 0, maxterm2 = 0; //������
	float cof;
	int cnt = 0; //��0��������
	scanf("%d", &n1);
	for (int i = 0; i<n1; i++)
	{
		scanf("%d %f", &exp, &cof);
		//   printf("%d %.1f\n",exp,cof);
		poly1[exp] = cof;
		if (exp>maxterm1)
			maxterm1 = exp;
	}
	scanf("%d", &n2);
	for (int i = 0; i<n2; i++)
	{
		scanf("%d %f", &exp, &cof);
		poly2[exp] = cof;
		//  printf("%d %.1f\n",exp,cof);
		if (exp>maxterm2)
			maxterm2 = exp;
	}
	//  printf("%d\n",maxterm1+maxterm2);
	for (int i = 0; i <= maxterm1; i++)
	{
		for (int j = 0; j <= maxterm2; j++)
		{
			poly3[i + j] += poly1[i] * poly2[j];
		}
	}
	for (int i = 0; i <= maxterm1 + maxterm2; i++)
	{
		if (poly3[i] != 0)
			cnt++;
	}
	printf("%d", cnt);
	for (int i = maxterm1 + maxterm2; i>-1; i--)
	if (poly3[i] != 0) printf(" %d %.1f", i, poly3[i]);
	return 0;
}

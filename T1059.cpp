#include"cstdio"
#include"algorithm"
#include"cmath"
using namespace std;
int main()
{
	long num;
	scanf("%ld", &num);
	if (num == 1)
		printf("1=1\n");
	else
	{
		printf("%ld=", num);
		for (int i = 2; i<3000; i++)
		{
			int cnt = 0;
			if (num%i == 0)
			{
				printf("%d", i);
				while (num%i == 0)
				{
					num /= i;
					cnt++;
				}
				if (cnt>1)
					printf("^%d", cnt);
				if (num>1)
					printf("*");
				else
					break;
			}
		}
	}
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	double sum = 0.0, temp;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		sum = sum + temp*(n - i + 1)*i;
	}
	printf("%.2f", sum);
	return 0;
}

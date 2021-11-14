#include <iostream>
using namespace std;
int main()
{
	long double a, b, c;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c;
		printf("Case #%d: %s\n", i, (a + b>c) ? "true" : "false");
	}
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int n, radix, index = 0, a[50], flag = 1;
	cin >> n >> radix;
	while (n)
	{
		a[index++] = n%radix;
		n /= radix;
	}
	for (int i = 0; i<index / 2; i++)
	{
		if (a[i] != a[index - 1 - i])
		{
			flag = 0;
			break;
		}
	}
	cout << (flag ? "Yes" : "No") << endl;
	for (int i = index - 1; i >= 0; i--)
	{
		cout << a[i];
		if (i) cout << " ";
	}
	return 0;
}

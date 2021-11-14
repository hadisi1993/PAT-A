#include <iostream>
#include<set>
using namespace std;
set<int>s;
int main()
{
	int n, val;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		int sum = 0;
		cin >> val;
		while (val)
		{
			sum += (val % 10);
			val /= 10;
		}
		s.insert(sum);
	}
	printf("%d\n", s.size());
	int flag = 1;
	for (auto c : s)
	{
		if (flag)
		{
			flag = 0;
			printf("%d", c);
		}
		else
			printf(" %d", c);
	}
	return 0;
}

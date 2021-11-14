#include <iostream>
#include<algorithm>
using namespace std;
struct mooncake
{
	double inventory;
	double price;
	double rate;
	bool operator <(const mooncake&a)
	{
		return rate>a.rate;
	}
}M[1005];
int main()
{
	int n, d;
	cin >> n >> d;
	for (int i = 0; i<n; i++)
	{
		cin >> M[i].inventory;
	}
	for (int i = 0; i<n; i++)
	{
		cin >> M[i].price;
		M[i].rate = M[i].price / M[i].inventory;
	}
	sort(M, M + n);
	double sum;
	int cnt = 0;
	while (d>0 && cnt<n)
	{
		if (d>M[cnt].inventory)
			sum += M[cnt].price;
		else
			sum += d*M[cnt].rate;
		d -= M[cnt].inventory;
		cnt++;
	}
	printf("%.2lf\n", sum);
	return 0;
}

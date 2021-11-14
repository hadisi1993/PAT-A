#include<iostream>
using namespace std;
int main()
{
	int first, k, n, sum = 0;
	cin >> first >> n >> k;
	int temp, data[100005], next[100005], ls[100005], res[100005];
	for (int i = 0; i<n; i++)
	{
		cin >> temp;
		cin >> data[temp] >> next[temp];   // 存储数据和位置
	}
	while (first != -1)
	{
		ls[sum++] = first;
		first = next[first];
	}
	for (int i = 0; i<n; i++)
		res[i] = ls[i];
	for (int i = 0; i<(sum - sum%k); i++)
		res[i] = ls[i / k*k + k - 1 - i%k];
	for (int i = 0; i<sum - 1; i++)
		printf("%05d %d %05d\n", res[i], data[res[i]], res[i + 1]);
	printf("%05d %d -1", res[sum - 1], data[res[sum - 1]]);
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>pre, in;
bool flag = true;
void postTravel(int preLeft, int inLeft, int inRight)
{
	if (inLeft>inRight)
	{
		return;
	}
	int i = inLeft;
	while (i <= inRight&&in[i] != pre[preLeft]) i++;
	postTravel(preLeft + 1, inLeft, i - 1);
	postTravel(preLeft + (i - inLeft) + 1, i + 1, inRight);
	if (flag)
	{
		printf("%d", pre[preLeft]);
		flag = false;
	}
}
int main()
{
	cin >> n;
	pre.resize(n), in.resize(n);
	for (int i = 0; i<n; i++)
		cin >> pre[i];
	for (int i = 0; i<n; i++)
		cin >> in[i];
	postTravel(0, 0, n - 1);
	return 0;
}

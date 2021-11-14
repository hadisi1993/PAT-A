#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i<n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int i;
	for (i = 0; i<n - 1; i++){
		if (v[i] >= 0 && v[i + 1] - v[i]>1){
			cout << v[i] + 1 << endl;
			break;
		}
	}
	if (i == n - 1){
		cout << (v[n - 1] >= 0 ? v[n - 1] + 1 : 1) << endl;
	}
	return 0;
}

#include <iostream>
#include<vector>
using namespace std;
bool isPrime(int n){
	for (int i = 2; i*i <= n; i++){
		if (n%i == 0) return false;
	}
	return true;
}
int main()
{
	int msize, n, m, val;
	cin >> msize >> n >> m;
	while (!isPrime(msize)) msize++;
	vector<int>hashtable(msize);
	for (int i = 0; i<n; i++){
		cin >> val;
		int j = 0;
		while (j<msize&&hashtable[(val + j*j) % msize]) j++;
		if (j<msize) hashtable[(val + j*j) % msize] = val;
		else printf("%d cannot be inserted.\n", val);
	}
	int cnt = 0;
	for (int i = 0; i<m; i++){
		cin >> val;
		for (int j = 0; j <= msize; j++){
			cnt++;
			if (hashtable[(val + j*j) % msize] == val || hashtable[(val + j*j) % msize] == 0)
				break;
		}
	}
	printf("%.1f", cnt*1.0 / m);
	return 0;
}

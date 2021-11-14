#include <iostream>
#include<vector>
#include<set>
using namespace std;
int n, m, a, b, k;
bool flag = true;

int main()
{
	cin >> n >> m;
	vector<int>v[n + 1];
	vector<int>dg(n + 1, 0);
	vector<int>ans;
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		v[a].push_back(b);
		dg[b]++;
	}
	cin >> k;
	for (int i = 0; i<k; i++){
		vector<int>tmp(n);
		vector<int>tmpdg = dg;
		for (int j = 0; j<n; j++)
			cin >> tmp[j];
		for (int j = 0; j<n; j++){
			if (tmpdg[tmp[j]] != 0){
				ans.push_back(i);
				break;
			}
			for (int l = 0; l<v[tmp[j]].size(); l++){
				tmpdg[v[tmp[j]][l]]--;
			}
		}
	}
	for (int i = 0; i<ans.size(); i++)
		printf("%s%d", i == 0 ? "" : " ", ans[i]);
	return 0;
}

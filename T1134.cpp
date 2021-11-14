#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
vector<int>v[10005];
int main()
{
	scanf("%d%d", &n, &m);
	int a, b, k, cnt, val;
	for (int i = 0; i<m; i++){
		scanf("%d%d", &a, &b);
		v[a].push_back(i);
		v[b].push_back(i);
	}
	scanf("%d", &k);
	for (int i = 0; i<k; i++){
		scanf("%d", &cnt);
		vector<int>hash(m, 0);
		int flag = 1;
		for (int j = 0; j<cnt; j++){
			scanf("%d", &val);
			for (int l = 0; l<v[val].size(); l++){
				hash[v[val][l]] = 1;
			}
		}
		for (int l = 0; l<m; l++)
		if (hash[l] == 0){
			flag = 0;
			break;
		}
		printf("%s\n", flag ? "Yes" : "No");
	}
	return 0;
}

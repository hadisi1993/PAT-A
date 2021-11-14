/*这道题首先要判断给出的图是否连通,然后再根据出入度数量计算*/
#include <iostream>
#include<vector>
using namespace std;
bool isConnected = false;  // 判断图是否连通
int n, m, s, t;
vector<vector<int>>edge;
vector<int>degree;
vector<bool>vis;
int cnt = 0;
void dfs(vector<vector<int>>&edge, int index){
	cnt++;
	vis[index] = true;
	for (int i = 0; i<edge[index].size(); i++){
		if (vis[edge[index][i]] == false)
			dfs(edge, edge[index][i]);
	}
}
int main()
{

	cin >> n >> m;
	edge.resize(n + 1);
	degree.resize(n + 1, 0);
	vis.resize(n + 1, false);
	for (int i = 0; i<m; i++){
		cin >> s >> t;
		edge[s].push_back(t);
		edge[t].push_back(s);
		degree[s]++;
		degree[t]++;
	}
	int even = 0, odd = 0;
	for (int i = 1; i <= n; i++){
		if (degree[i] % 2) odd++;
		else even++;
	}
	dfs(edge, 1);
	for (int i = 1; i <= n; i++){
		if (i != 1) cout << " ";
		cout << degree[i];
	}
	cout << endl;
	if (cnt == n) isConnected = true;
	if (isConnected){
		if (even == n){
			cout << "Eulerian" << endl;
		}
		else if (odd == 2 && even == n - 2){
			cout << "Semi-Eulerian" << endl;
		}
		else{
			cout << "Non-Eulerian" << endl;
		}
	}
	else{
		cout << "Non-Eulerian" << endl;
	}
	return 0;
}

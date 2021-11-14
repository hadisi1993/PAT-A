#include<iostream>
#include<vector>
#include<set>
using namespace std;
struct line{
	int s, t;
};
int main()
{
	int n, m;
	cin >> n >> m;
	vector<line>edges;
	vector<int>vertex(n);
	int s, t;
	for (int i = 0; i<m; i++){
		cin >> s >> t;
		edges.push_back({ s, t });
	}
	int k;
	cin >> k;
	for (int i = 0; i<k; i++){
		set<int>colors;
		int flag = 0;
		int tmp;
		for (int j = 0; j<n; j++){
			cin >> vertex[j];
			colors.insert(vertex[j]);
		}
		for (int j = 0; j<m; j++){
			if (vertex[edges[j].s] == vertex[edges[j].t]){
				flag = 1;
				break;
			}
		}
		flag == 1 ? printf("No\n") : printf("%d-coloring\n", colors.size());
	}
	return 0;
}

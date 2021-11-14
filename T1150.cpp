#include <iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
const int INF = 0x7fffffff;
int n, m;
int main()
{
	cin >> n >> m;
	vector<vector<int>>edges(n + 1, vector<int>(n + 1, INF));
	int s, t, v;
	for (int i = 0; i<m; i++){
		cin >> s >> t >> v;
		edges[s][t] = v;
		edges[t][s] = v;
	}
	int k, shortestDist = INF;
	cin >> k;
	int pathNum, idx = 1;
	bool isSample, isCycle, isNa;  //判断是否是简单cycle,是否是Cycle
	for (int i = 0; i<k; i++){
		isSample = isCycle = true, isNa = false;
		unordered_set<int>s;
		cin >> pathNum;
		int pre, cur, start;
		int sum = 0;
		for (int j = 0; j<pathNum - 1; j++){
			if (j == 0){
				cin >> pre;
				start = pre;  // 设定起点
				s.insert(pre);
			}
			else{
				cin >> cur;
				if (edges[pre][cur] == INF){
					isCycle = false;
					isNa = true;
				}
				else{
					if (s.find(cur) != s.end()){
						isSample = false;
					}
					sum += edges[pre][cur];
				}
				s.insert(cur);
				pre = cur;
			}
		}
		if (s.size()<n) isCycle = false;
		cin >> cur;
		if (isNa == false){
			if (edges[pre][cur] == INF){
				isCycle = false;
				isNa = true;
			}
			else{
				if (cur != start) isCycle = false;
				sum += edges[pre][cur];
			}
		}
		if (isCycle){
			if (shortestDist>sum){
				idx = i + 1;
				shortestDist = sum;
			}
		}
		printf("Path %d: ", i + 1);
		if (isCycle == false){
			if (isNa) printf("NA (Not a TS cycle)\n");
			else printf("%d (Not a TS cycle)\n", sum);
		}
		else{
			if (isSample){
				printf("%d (TS simple cycle)\n", sum);
			}
			else{
				printf("%d (TS cycle)\n", sum);
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n", idx, shortestDist);
	return 0;
}

#include <iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<unordered_set>
using namespace std;
int n, m;
int main()
{
	unordered_map<string, vector<string>>incompatible;
	cin >> n >> m;
	string a, b;
	for (int i = 0; i<n; i++){
		cin >> a >> b;
		incompatible[a].push_back(b);
		incompatible[b].push_back(a);
	}
	for (int i = 0; i<m; i++){
		int k;
		string tmp;
		unordered_set<string>s;
		s.clear();
		cin >> k;
		int flag = 0;
		for (int j = 0; j<k; j++){
			cin >> tmp;
			if (s.find(tmp) != s.end()){  //���Ҹ���Ʒ�Ƿ���Σ��Ʒ
				flag = 1;
				//break;
			}
			if (flag) break;
			for (auto it : incompatible[tmp]){  //�������п��ܵ�Σ��Ʒ
				s.insert(it);
			}
		}
		printf("%s\n", flag ? "No" : "Yes");
	}
	return 0;
}

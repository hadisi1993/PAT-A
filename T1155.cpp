#include <iostream>
#include<vector>
using namespace std;
int n;
int flag; //0����Ƕ�,1����󶥶�,2����С����
void dfs(vector<int>&heaps, int index, vector<int>&ans){
	if (ans.size()>0 && flag == 1 && heaps[index]>ans[ans.size() - 1]) flag = 0;  //�����ж�
	if (ans.size()>0 && flag == 2 && heaps[index]<ans[ans.size() - 1]) flag = 0;
	ans.push_back(heaps[index]);
	if (2 * index + 1 >= heaps.size() && 2 * index + 2 >= heaps.size()){  //��ӡ���
		for (int i = 0; i<ans.size(); i++){
			if (i) printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
		ans.pop_back();
		return;
	}
	if (2 * index + 2<heaps.size()){
		dfs(heaps, 2 * index + 2, ans);
	}
	if (2 * index + 1<heaps.size()){
		dfs(heaps, 2 * index + 1, ans);
	}
	ans.pop_back();
}
int main()
{
	cin >> n;
	vector<int>heaps(n), ans;
	for (int i = 0; i<n; i++){
		cin >> heaps[i];
	}
	if (heaps[0]>heaps[1]) flag = 1;  //�󶥶�
	else flag = 2;                  //С����
	dfs(heaps, 0, ans);
	if (flag == 0){
		printf("Not Heap\n");
	}
	else if (flag == 1){
		printf("Max Heap\n");
	}
	else{
		printf("Min Heap\n");
	}
	return 0;
}

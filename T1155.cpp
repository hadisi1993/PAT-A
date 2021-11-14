#include <iostream>
#include<vector>
using namespace std;
int n;
int flag; //0代表非堆,1代表大顶堆,2代表小顶堆
void dfs(vector<int>&heaps, int index, vector<int>&ans){
	if (ans.size()>0 && flag == 1 && heaps[index]>ans[ans.size() - 1]) flag = 0;  //首先判断
	if (ans.size()>0 && flag == 2 && heaps[index]<ans[ans.size() - 1]) flag = 0;
	ans.push_back(heaps[index]);
	if (2 * index + 1 >= heaps.size() && 2 * index + 2 >= heaps.size()){  //打印结果
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
	if (heaps[0]>heaps[1]) flag = 1;  //大顶堆
	else flag = 2;                  //小顶堆
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

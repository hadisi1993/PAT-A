#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	node(int v, int l) :val(v), level(l){}
	int val;
	int level;
	node*left, *right;
};
node*createTree(vector<int>&inorder, vector<int>&postorder, int inLeft, int inRight, int postLeft, int postRight, int depth){
	if (inLeft>inRight) return nullptr;
	node*tmp = new node(postorder[postRight], depth);
	int index = find(inorder.begin(), inorder.end(), postorder[postRight]) - inorder.begin();
	tmp->left = createTree(inorder, postorder, inLeft, index - 1, postLeft, postLeft + index - inLeft - 1, depth + 1);
	tmp->right = createTree(inorder, postorder, index + 1, inRight, postLeft + index - inLeft, postRight - 1, depth + 1);
	return tmp;
}
void levelOrder(node*root){
	queue<node*>q;
	q.push(root);
	while (!q.empty()){
		node*tmp = q.front();
		q.pop();
		cout << tmp->val << " ";
		if (tmp->left != nullptr) q.push(tmp->left);
		if (tmp->right != nullptr) q.push(tmp->right);
	}
}
void ZigZaggingPrint(node*root){
	vector<int>v;
	queue<node*>q;
	q.push(root);
	int curDepth = 0;
	while (!q.empty()){
		node*tmp = q.front();
		q.pop();
		if (tmp->level == curDepth){
			v.push_back(tmp->val);
		}
		else{
			if (curDepth % 2 == 0) reverse(v.begin(), v.end());
			for (int i = 0; i<v.size(); i++){
				if (curDepth == 0) cout << v[i];
				else cout << " " << v[i];
			}
			curDepth += 1;
			v.clear();
			v.push_back(tmp->val);
		}
		if (tmp->left != nullptr) q.push(tmp->left);
		if (tmp->right != nullptr) q.push(tmp->right);
	}
	if (curDepth % 2 == 0) reverse(v.begin(), v.end());
	for (int i = 0; i<v.size(); i++){
		if (curDepth == 0) cout << v[i];
		else cout << " " << v[i];
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int>postorder(n), inorder(n);
	for (int i = 0; i<n; i++){
		cin >> inorder[i];
	}
	for (int i = 0; i<n; i++){
		cin >> postorder[i];
	}
	node*root = createTree(inorder, postorder, 0, n - 1, 0, n - 1, 0);
	ZigZaggingPrint(root);
	//levelOrder(root);
	return 0;
}

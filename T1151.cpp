#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int val;
	node*left, *right;
	node(int v) :val(v){}
};
int n, m;
node*buildTree(vector<int>&preorder, vector<int>&inorder, int preLeft, int preRight, int inLeft, int inRight){
	if (inLeft>inRight) return nullptr;
	node*tmp = new node(preorder[preLeft]);
	int index = find(inorder.begin(), inorder.end(), preorder[preLeft]) - inorder.begin();
	tmp->left = buildTree(preorder, inorder, preLeft + 1, preLeft + index - inLeft, inLeft, index - 1);
	tmp->right = buildTree(preorder, inorder, preLeft + index - inLeft + 1, preRight, index + 1, inRight);
	return tmp;
}

node*lowestCommonAncestor(node*root, int p, int q){
	if (root == nullptr) return nullptr;
	if (root->val == p || root->val == q) return root;
	node*left = lowestCommonAncestor(root->left, p, q);
	node*right = lowestCommonAncestor(root->right, p, q);
	if (left&&right){
		return root;
	}
	else{
		return left == nullptr ? right : left;
	}
}

int main()
{
	cin >> n >> m;
	vector<int>inorder(m), preorder(m);
	for (int i = 0; i<m; i++)
		cin >> inorder[i];
	for (int i = 0; i<m; i++)
		cin >> preorder[i];
	node*root = buildTree(preorder, inorder, 0, m - 1, 0, m - 1);
	int p, q;
	bool existq, existp;
	for (int i = 0; i<n; i++){
		cin >> p >> q;
		existq = existp = true;
		if (find(preorder.begin(), preorder.end(), p) == preorder.end()) existp = false;
		if (find(preorder.begin(), preorder.end(), q) == preorder.end()) existq = false;
		if (existp == false && existq == false){
			printf("ERROR: %d and %d are not found.\n", p, q);
		}
		else if (existp == false || existq == false){
			if (existp == false) printf("ERROR: %d is not found.\n", p);
			else printf("ERROR: %d is not found.\n", q);
		}
		else {
			node*lca = lowestCommonAncestor(root, p, q);
			if (lca->val == p){
				printf("%d is an ancestor of %d.\n", p, q);
			}
			else if (lca->val == q){
				printf("%d is an ancestor of %d.\n", q, p);
			}
			else{
				printf("LCA of %d and %d is %d.\n", p, q, lca->val);
			}
		}
	}
	return 0;
}


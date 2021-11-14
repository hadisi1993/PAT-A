/*判断一棵树是不是红黑树*/
#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n, k;
struct node{
	int val;
	node*left, *right;
};
node*createTree(vector<int>& inorder, vector<int>&preorder, int inLeft, int inRight, int preLeft, int preRight){ //创建一颗树
	if (inLeft>inRight) return nullptr;
	node*tmp = new node();
	tmp->val = preorder[preLeft];
	int index = inLeft;
	while (index <= inRight&&inorder[index] != preorder[preLeft]) index++;
	tmp->left = createTree(inorder, preorder, inLeft, index - 1, preLeft + 1, preLeft + index - inLeft);
	tmp->right = createTree(inorder, preorder, index + 1, inRight, preLeft + index - inLeft + 1, preRight);
	return tmp;
}
bool checkChild(node*root){  //判断红节点的孩子节点是不是黑色的
	if (root == nullptr) return true;
	if (root->val<0 && ((root->left != nullptr&&root->left->val<0) || (root->right != nullptr&&root->right->val<0)))
		return false;
	return checkChild(root->left) && checkChild(root->right);
}
int checkBlackNum(node*root){   //判断路径上是否有相同数量的黑节点
	if (root == nullptr) return 0;
	int leftNum = checkBlackNum(root->left), rightNum = checkBlackNum(root->right);
	if (leftNum == -1 || rightNum == -1 || leftNum != rightNum) return -1;
	if (root->val<0) return leftNum;
	else return leftNum + 1;
}
bool check(node*root){    //判断一棵树是不是红黑树
	if (root == nullptr || root->val<0) return false; //判断根节点是不是黑色的
	if (checkChild(root) == false || checkBlackNum(root) == -1) return false;
	return true;
}
int main()
{
	cin >> k;
	while (k--){
		cin >> n;
		vector<int>preorder(n);
		for (int i = 0; i<n; i++){
			cin >> preorder[i];
		}
		vector<int>inorder = preorder;
		sort(inorder.begin(), inorder.end(), [](int a, int b){return abs(a)<abs(b); }); // 获取中序遍历结果
		node*tree = createTree(inorder, preorder, 0, n - 1, 0, n - 1);
		printf("%s\n", check(tree) ? "Yes" : "No");
	}
	return 0;
}

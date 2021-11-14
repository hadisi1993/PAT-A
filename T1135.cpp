/*�ж�һ�����ǲ��Ǻ����*/
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
node*createTree(vector<int>& inorder, vector<int>&preorder, int inLeft, int inRight, int preLeft, int preRight){ //����һ����
	if (inLeft>inRight) return nullptr;
	node*tmp = new node();
	tmp->val = preorder[preLeft];
	int index = inLeft;
	while (index <= inRight&&inorder[index] != preorder[preLeft]) index++;
	tmp->left = createTree(inorder, preorder, inLeft, index - 1, preLeft + 1, preLeft + index - inLeft);
	tmp->right = createTree(inorder, preorder, index + 1, inRight, preLeft + index - inLeft + 1, preRight);
	return tmp;
}
bool checkChild(node*root){  //�жϺ�ڵ�ĺ��ӽڵ��ǲ��Ǻ�ɫ��
	if (root == nullptr) return true;
	if (root->val<0 && ((root->left != nullptr&&root->left->val<0) || (root->right != nullptr&&root->right->val<0)))
		return false;
	return checkChild(root->left) && checkChild(root->right);
}
int checkBlackNum(node*root){   //�ж�·�����Ƿ�����ͬ�����ĺڽڵ�
	if (root == nullptr) return 0;
	int leftNum = checkBlackNum(root->left), rightNum = checkBlackNum(root->right);
	if (leftNum == -1 || rightNum == -1 || leftNum != rightNum) return -1;
	if (root->val<0) return leftNum;
	else return leftNum + 1;
}
bool check(node*root){    //�ж�һ�����ǲ��Ǻ����
	if (root == nullptr || root->val<0) return false; //�жϸ��ڵ��ǲ��Ǻ�ɫ��
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
		sort(inorder.begin(), inorder.end(), [](int a, int b){return abs(a)<abs(b); }); // ��ȡ����������
		node*tree = createTree(inorder, preorder, 0, n - 1, 0, n - 1);
		printf("%s\n", check(tree) ? "Yes" : "No");
	}
	return 0;
}

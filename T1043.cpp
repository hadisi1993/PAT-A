#include<iostream>
#include<vector>
using namespace std;
/*�жϰ��ո������н������ǲ��Ƕ���������,��Ҫ�������ڹ��ڶ�����������һϵ�в���*/
vector<int>origin, pre, preM, post, postM;
struct node  // ���Ľڵ�
{
	int data;
	node*left;
	node*right;
};
void insert(node*&root, int data)
{
	if (root == NULL)
	{
		root = new node;  // ����һ���ڵ�
		root->data = data;  // ��������
		root->left = root->right = NULL;
		return;
	}
	if (data<root->data)
		insert(root->left, data);
	else
		insert(root->right, data);
}
void preOrder(node*&root, vector<int>&vi)   // ԭ����ǰ�����
{
	if (root == NULL)
		return;
	vi.push_back(root->data);
	preOrder(root->left, vi);
	preOrder(root->right, vi);
}
void preMOrder(node*&root, vector<int>&vi)  // ��������ǰ�����
{
	if (root == NULL)
		return;
	vi.push_back(root->data);
	preMOrder(root->right, vi);
	preMOrder(root->left, vi);

}
void postOrder(node*&root, vector<int>&vi)  // ԭ���ĺ������
{
	if (root == NULL)
		return;
	postOrder(root->left, vi);
	postOrder(root->right, vi);
	vi.push_back(root->data);
}
void postMOrder(node*&root, vector<int>&vi)   // �������ĺ������
{
	if (root == NULL)
		return;
	postMOrder(root->right, vi);
	postMOrder(root->left, vi);
	vi.push_back(root->data);
}
int main()
{
	int n, v;
	scanf("%d", &n);
	node*root = NULL;// ���ڵ�
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &v);
		insert(root, v);  // ����
		origin.push_back(v);  // ����ԭʼ����
	}
	preOrder(root, pre);
	preMOrder(root, preM);
	postOrder(root, post);
	postMOrder(root, postM);
	if (origin == pre)
	{
		printf("YES\n");
		for (int i = 0; i<post.size(); i++)
			i>0 ? printf(" %d", post[i]) : printf("%d", post[i]);
	}
	else if (origin == preM)
	{
		printf("YES\n");
		for (int i = 0; i<postM.size(); i++)
			i>0 ? printf(" %d", postM[i]) : printf("%d", postM[i]);
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}

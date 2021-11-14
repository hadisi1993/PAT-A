#include <iostream>
using namespace std;
int maxlevel = -1, n;
int a[1005], depth[1005];
struct node
{
	int data, level;
	node*lchild, *rchild;
	node(int _data, int _level) :data(_data), level(_level)
	{
		lchild = nullptr;
		rchild = nullptr;
	}
};
void insertNode(int data, int level, node*&Node)
{
	if (!Node)
	{
		Node = new node(data, level);
		depth[level]++;
		if (level>maxlevel)
			maxlevel = level;
		return;
	}
	Node->data >= data ? insertNode(data, level + 1, Node->lchild) : insertNode(data, level + 1, Node->rchild);
}
void buildBSTree(int a[], int len, node*&BSTree)
{
	for (int i = 0; i<len; i++)
		insertNode(a[i], 0, BSTree);
}
int main()
{
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> a[i];
	node*BSTree = nullptr;
	buildBSTree(a, n, BSTree);
	cout << depth[maxlevel] << " + " << depth[maxlevel - 1] << " = " << depth[maxlevel] + depth[maxlevel - 1] << endl;
	return 0;
}

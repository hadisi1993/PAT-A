#include<iostream>
#include<queue>
using namespace std;
const int maxn = 35;
/*�������ǰ�����Ƚ϶���ˣ��������ý����ٱ����ķ�����һ��*/
int postorder[maxn], inorder[maxn];
struct node{
	int data; //����
	node*leftchild;
	node*rightchild;
};
node*newnode(int x)   //xΪ����
{
	node*root = new node;   //����һ���µĽڵ�
	root->data = x;
	root->leftchild = NULL;
	root->rightchild = NULL;
	return root;
}
void createlevelorder(node*&now, int pl, int pr, int il, int ir)         //������α����ĺ���
{
	if (pl>pr || il>ir)
		return;                   //����û�нڵ�

	now = newnode(postorder[pr]);  //���ڵ㸳ֵ
	int index;
	for (int i = il; i <= ir; i++)                  //������������ҵ����ڵ�
	{
		if (inorder[i] == postorder[pr])
		{
			index = i;
			break;
		}
	}
	int llen = index - il;            //�������ڵ����
	int rlen = ir - index;            //�������ڵ����
	createlevelorder(now->leftchild, pr - llen - rlen, pr - rlen - 1, il, index - 1); //����������
	createlevelorder(now->rightchild, pr - rlen, pr - 1, index + 1, ir);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &postorder[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &inorder[i]);
	node*r;
	createlevelorder(r, 1, n, 1, n);    // ����
	//������Ϻ���в�α���
	queue<node*>q;        //�������У�ע������洢�ڵ�ĵ�ַ
	q.push(r);
	int flag = 0;
	while (!q.empty())
	{
		node*x = q.front();
		if (!flag)
		{
			printf("%d", x->data);
			flag = 1;
		}
		else
		{
			printf(" %d", x->data);
		}
		if (x->leftchild != NULL)
			q.push(x->leftchild);
		if (x->rightchild != NULL)
			q.push(x->rightchild);
		q.pop();
	}

	return 0;
}

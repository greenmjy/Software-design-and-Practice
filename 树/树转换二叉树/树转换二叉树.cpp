#include <string>
#include<iostream>
using namespace std;
struct Node {                   //�Ա����ʽ�洢�������
	char data;
	int parent;
	int lchild;
	int rchild;
};
struct TreeNode {                //�Զ�������洢�����Ľ��
	char data;
	TreeNode* l;
	TreeNode* r;
};
int creattable(Node table[]){  //�������ı�ת��Ϊ������
	int n, k, i, j;
	cout << "���������:(<20)";
	cin >> n;
	if (n>0){
		cout << "��������Ϣ��˫�ױ��(��һ��������������Ϣ��a - 1 ):" << endl;
		for (i = 0; i < n; i++){
			cin >> table[i].data >> table[i].parent;
			table[i].lchild = table[i].rchild = 0;
		}
		for (i = 0; i < n; i++){           //ת������
			for (j = 1; j < n; j++){
				if (table[j].parent == i)    //���û������������Ϊ��������
				if (table[i].lchild == 0){
					table[i].lchild = j;
					k = j;
				}
				else{                         //��������������������������������չ
					table[k].rchild = j;
					k = j;
				}
			}
		}
	}
	return n;
}
void Build(TreeNode*& current, Node node[], int pos, int n){ //����ת��Ϊ��������
	if (n>0)
	{
		if (current == 0){
			current = new TreeNode;
			current->l = current->r = 0;
		}
		current->data = node[pos].data;
		if (node[pos].lchild)
			Build(current->l, node, node[pos].lchild, n);
		if (node[pos].rchild)
			Build(current->r, node, node[pos].rchild, n);
	}
}

void Preorder(TreeNode* root){ //���������
	TreeNode* current = root;
	if (current != 0){
		cout << current->data << " ";
		Preorder(current->l);
		Preorder(current->r);
	}
}

void Inorder(TreeNode*root) //���������
{
	TreeNode*current = root;
	if (current)
	{
		Inorder(current->l);
		cout << current->data << " ";
		Inorder(current->r);
	}
}
int main(){
	Node node[20];
	int n = creattable(node);
	TreeNode* root = 0;

	Build(root, node, 0, n);
	if (root){
		cout << "�����������������";
		Preorder(root);
		cout << endl;
		cout << "�����������������";
		Inorder(root);
		cout << endl;
	}
	else
		cout << "������" << endl;
	system("PAUSE");
	return 1;
}
/*
���������:(<20)5
��������Ϣ��˫�ױ��(��һ��������������Ϣ��a - 1 ):
a -1
b 0
c 0
d 0
e 1
�����������������a b e c d
�����������������e b c d a
�밴���������. . .

���Ľṹ��
     a
  b  c  d
e

�������Ľṹ��
        a
	b
e     c
         d
*/
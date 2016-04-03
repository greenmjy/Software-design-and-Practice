/**< ��������� */
#include <iostream>
#include<ctime>

using namespace std;
template<class T>
class node
{
public:
    node()
    {
     lchild = rchild=NULL;
    }
    T data;
    node *lchild,*rchild;
};

template<class T>
class BST
{
public:
    node<T>* search_insert(node<T>*,T);
    void insert_BST(node<T>*&root,T);
    void pre_order(node<T>*);
	void in_order(node<T>*);
    T delete_BST(node<T>*&root);//ɾ���ؼ�����С�Ľڵ�
	void Delete(node<T>*&root, T t);//ɾ���ؼ���Ϊt�Ľڵ�

private:
    node<T> *root;
};

template<class T>
node<T>* BST<T>::search_insert(node<T> *root,T t)
{
    node<T>*s=NULL,*p=root;
	if (p == NULL)
		return NULL;
	else if (p->data == t)
		return p;
	else if (t < p->data)
		return(search_insert(p->lchild, t));
	else if (t>p->data)
		return(search_insert(p->rchild, t));
}

template<class T>
void BST<T>::insert_BST(node<T>*&root,T t)
{
	if (root == NULL)
	{
		node<T>*p = new node<T>;
		p->data = t;
		p->lchild = NULL;
		p->rchild = NULL;
		root = p;
	}
	else if (t < root->data)
		insert_BST(root->lchild, t);
	else if (t>root->data)
		insert_BST(root->rchild, t);
}

template<class T>
void BST<T>::pre_order(node<T>*root)
{
    if(root)
    {
        cout<<root->data<<" ";
        pre_order(root->lchild);
        pre_order(root->rchild);
    }
}

template<class T>
void BST<T>::in_order(node<T>*root)
{
	if (root)
	{
		in_order(root->lchild);
		cout << root->data << " ";
		in_order(root->rchild);
	}
}
template<class T>
T  BST<T>::delete_BST(node<T>*&root)//ɾ���ؼ�����С�Ľڵ�
{
	T temp;
	node<T>*p = new node<T>;
	if (root->lchild == NULL)
	{
		p = root;
		temp = root->data;
		root = root->rchild;
		delete p;
		return temp;
	}
	else return (delete_BST(root->lchild));
}

template<class T>
void BST<T>::Delete(node<T>*&root, T t)
{
	if (root != NULL)
	{
		if (t < root->data)
			Delete(root->lchild, t);
		else if (t>root->data)
			Delete(root->rchild, t);
		else
		if (root->lchild == NULL)
			root = root->rchild;
		else if (root->rchild == NULL)
			root = root->lchild;
		else
			root->data = delete_BST(root->rchild);
	}
}



int main()
{
    int i;
    BST<int> bstree;
    node<int> *root=NULL;
	srand(unsigned int(time));
	for (i = 1; i < 11; i++)
	{   
		int a = rand() % 100;
		bstree.insert_BST(root, a);//�ȸ�����
		cout << a << " ";
	}
	cout << endl;
	cout << "�ȸ�������� ";
    bstree.pre_order(root);//�ȸ��������
	cout << endl;
	cout << "�и�������� ";
	bstree.in_order(root);//�и��������
    cout<<endl;
	cout << "ɾ���ؼ�ֵ��С�Ľڵ㣺";
	cout << bstree.delete_BST(root) << endl;
	cout << "ɾ����Ľ��(�������)��";
	bstree.pre_order(root);
	cout << endl;
	int b;
	cout << "ɾ��b";
	cin >> b;
	cout << "ɾ��b�����(�������)��";
	bstree.Delete(root, b);
    bstree.pre_order(root);
    cout<<endl;
    return 0;
}

/*
9 66 95 41 92 63 67 14 0 33
�ȸ�������� 9 0 66 41 14 33 63 95 92 67
�и�������� 0 9 14 33 41 63 66 67 92 95
ɾ���ؼ�ֵ��С�Ľڵ㣺0
ɾ����Ľ��(�������)��9 66 41 14 33 63 95 92 67
ɾ��b 66
ɾ��b�����(�������)��9 67 41 14 33 63 95 92



*/
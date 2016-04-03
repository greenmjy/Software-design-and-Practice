#include<iostream>
#define MAX 30           //���ڵ�������
using namespace std;

template<class T>
class node
{
public:
	node()
	{
		child = nextsibling = NULL;
	}
	T ele; //�ڵ�ֵ
	node*child, *nextsibling;//��������ֵ�
};

template<class T>
class Mytree
{
public:
	Mytree()
	{
		tree = NULL;
	}
	~Mytree()
	{
		delete tree;
	}
	void CreatTree(node<T>**);               //���캢���ֵܱ�ʾ������

	T GetParent(node<T>*,T t);                       //�������ĸ��׽ڵ�
	T GetLeftChild(node<T>*,T);               //���������������
	T GetRightsibling(node<T>*,T);            //�������������ֵ�
	T GetRoot(node<T>*);                    //�������ĸ��ڵ�
	node<T>* RetPoint(T, node<T>*);        //����ֵΪt�Ľڵ��ָ��
	node<T>* RetParentPoint(T, node<T>*);//����ֵΪt�Ľڵ㸸��ָ��

	void Display(node<T>*);        //������������ֵܱ�ʾ����ǰ�����򡢺������
private:
	void preTraverseTree(node<T>*);   //�ݹ��������
	void InTraverseTree(node<T>*);    //�ݹ��������
	void PostTraverseTree(node<T>*);  //�ݹ�������
	node<T> *tree;
};

template<class T>
void Mytree<T>::CreatTree(node<T>**tree)                                     //������������ֵܱ�ʾ����
{    
                                                                       //��treeΪ���ڵ㹹��
	if ((*tree) != NULL)
	{
		cout << "����ڵ�" << (*tree)->ele << "����������ֵ�(û�еĻ�����#)��";
		node<T>*a = new node<T>;
		node<T>*b = new node<T>;
		cin >> a->ele >> b->ele;
		if (a->ele != '#') (*tree)->child = a; //�������
		else (*tree)->child = NULL;
		if (b->ele != '#') (*tree)->nextsibling = b; //�����ֵ�
		else (*tree)->nextsibling = NULL;
		CreatTree(&(*tree)->child);             //�ݹ鹹����
		CreatTree(&(*tree)->nextsibling);
	}
}

template<class T>
T Mytree<T>::GetParent(node<T> *tree,T t)                                   //���ؽڵ�ֵΪt�ĸ���
{
	node<T>*p = RetParentPoint(t, tree);
	if (p)	return p->ele;
	else return NULL;
}

template<class T>
T Mytree<T>::GetRoot(node<T>*tree)                                          //�������ĸ��ڵ�ֵ
{
	return tree->ele;
}
template<class T>
T Mytree<T>::GetLeftChild(node<T>*tree,T t)                    //�������������
{
	
	node<T>*p=RetPoint(t, tree);
	if (p&&p->child) return p->child->ele;
	else return NULL;
}

template<class T>
T Mytree<T>::GetRightsibling(node<T>*tree,T t)                //�õ���tree�����ֵ�
{
	node<T>*p=RetPoint(t, tree);
	if (p&&p->nextsibling) return p->nextsibling->ele;
	else return NULL;
}

template<class T>
void Mytree<T>::Display(node<T>*tree)                               //���ֵݹ����
{
	cout << "����ݹ������";
	preTraverseTree(tree);
	cout << endl;
	cout << "����ݹ������";
	InTraverseTree(tree);
	cout <<endl;
	cout << "����ݹ������";
	PostTraverseTree(tree);
	cout << endl;
}

template<class T>
void Mytree<T>::preTraverseTree(node<T>*tree)  //����ݹ����
{
	if (tree)
	{
		cout << tree->ele << " ";
		preTraverseTree(tree->child);
		preTraverseTree(tree->nextsibling);
	}
}

template <class T>
void Mytree<T>::InTraverseTree(node<T>*tree)  //����ݹ����
{
	if (tree)
	{
		InTraverseTree(tree->child);
		cout << tree->ele << "��";
		InTraverseTree(tree->nextsibling);
	}
}

template<class T>
void Mytree<T>::PostTraverseTree(node<T>*tree)  //����ݹ����
{
	if(tree)
	{
		PostTraverseTree(tree->nextsibling);
		PostTraverseTree(tree->child);
		cout << tree->ele << " ";
	}
}

template<class T>
node<T>* Mytree<T>::RetPoint(T t, node<T>* tree)     //�������ڵ�ֵΪt��ָ��
{
	if (tree)
	{
		if (tree->ele == t) return tree;
		else if (RetPoint(t, tree->child)!=NULL)
		{
		return RetPoint(t, tree->child);
	
		}
		else if (RetPoint(t, tree->nextsibling) != NULL)
		{
		return RetPoint(t, tree->nextsibling);
		}
		else  return NULL;
	}
	else return NULL;
}

template<class T>
node<T>* Mytree<T>::RetParentPoint(T t, node<T>*tree)
{
	if (tree&&tree->child)
	{
		if (tree->ele == t)  return tree;
		else if (RetParentPoint(t, tree->child))
			return RetParentPoint(t, tree->child);
		else if (RetParentPoint(t, tree->nextsibling))
			return RetParentPoint(t, tree->nextsibling);
		else return NULL;
	}
}
int main()
{
	Mytree<char> mytree;
	node<char> *root = new node<char>;
	cout << "������ڵ㣺";
	cin >> root->ele;
	mytree.CreatTree(&root);
	cout<<"���ĸ���"<<mytree.GetRoot(root)<<endl;

	cout << "����t��";
	char t;
	cin >> t;
	cout << "t�������" << mytree.GetLeftChild(root, t) << endl;
	cout << "t�����ֵ�" << mytree.GetRightsibling(root, t) << endl;
	cout << "t�ĸ��ڵ㣺" << mytree.GetParent(root,t) << endl;
	cout << "������������ֵܱ�ʾ�������ֱ�����" << endl;
	mytree.Display(root);
	return 0;
}

/*
������ڵ㣺a
����ڵ�a����������ֵ�(û�еĻ�����#)��b c
����ڵ�b����������ֵ�(û�еĻ�����#)��d e
����ڵ�d����������ֵ�(û�еĻ�����#)��# #
����ڵ�e����������ֵ�(û�еĻ�����#)��f g
����ڵ�f����������ֵ�(û�еĻ�����#)��# #
����ڵ�g����������ֵ�(û�еĻ�����#)��# #
����ڵ�c����������ֵ�(û�еĻ�����#)��h #
����ڵ�h����������ֵ�(û�еĻ�����#)��# #
���ĸ���a
����t��c
t�������h
t�����ֵ�



*/
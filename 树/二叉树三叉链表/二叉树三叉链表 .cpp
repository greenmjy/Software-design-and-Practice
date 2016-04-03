#include <iostream>
#include<queue>
#include"myqueue.h"
#include"myqueue.cpp"
using namespace std;
template<class T>
class Node                             //�ڵ���
{
public:
    Node()
    {
        parent=lchild=rchild=NULL;
    }
    T value;
    Node *parent,*lchild,*rchild;
};

template<class T>
class Mytree
{
public:
    Mytree(){tree = new Node<T>;}
    ~Mytree(){delete tree;}


	void Creat(Node<T>**tree);
	void creatTree(Node<T>*&tree);

    bool Isempty(Node<T>*tree);                //�п�
             
    T GetRoot(Node<T>*tree);                 //�������ĸ�
	T GetParent(Node<T>*tree,T);             //�õ�ĳ���ڵ��˫��
	int  getheight(Node<T>*tree);            //�������ĸ߶�

    void DeleteNode(Node<T>*,T);             //ɾ���˽ڵ����
	void clearTree(Node<T>*&tree);
          
	void display(Node<T>*tree);             //�ȸ��������
	Node<T>* levelorder(Node<T>*tree, T);     //�ô�ڵ�T��ָ��
	
private:
    Node<T> *tree;
    int flag=0;
};

/**< �������������ʾ�Ķ����� */
/**< ������������� */

template<class T>
void Mytree<T>::Creat(Node<T> **tree)   //���������
{
    T x;
    cin>>x;
    if(x=='#') *tree = NULL;
    else{
        if(!tree) return;
		(*tree) = new Node<T>;
        (*tree)->value = x;
        Creat(&(*tree)->lchild);
        Creat(&(*tree)->rchild);
    }
}
template<class T>
void Mytree<T>::creatTree(Node<T>*& tree)  //������˫�׵Ĺ���,��������ҵ�����Ӧ�ĸ��׸���parent
{
  queue<Node<T>*> q;
  Node<T> *newtree=new Node<T>;
  Creat(&tree);        //�����������ȱ˫�ף�
  cout << "���������������" << endl;
  //display(tree); 
  if (tree)  //���ڵ㸸��ָ��Ϊ��
  {
	  tree->parent = NULL;
  }

  q.push(tree);  //���ڵ����
  while(!q.empty())
  {
      newtree = q.front();  
      q.pop();
      if(newtree->lchild)   
      {
          newtree->lchild->parent=newtree;
          q.push(newtree->lchild);
      }
      if(newtree->rchild)
      {
          newtree->rchild->parent=newtree;
          q.push(newtree->rchild);
      }
  }
}

template<class T>
bool Mytree<T>::Isempty(Node<T>*tree)
{
	if (tree) return false;
	else return true;
}
/**< �����ĸ߶� */

template<class T>
int Mytree<T>::getheight(Node<T>* tree)
{
    int lhigh=0,rhigh=0;
    if(!tree) return 0;
    if(tree->lchild)
        lhigh = getheight(tree->lchild);
    if(tree->rchild)
        rhigh = getheight(tree->rchild);
    return lhigh > rhigh ? lhigh+1: rhigh+1;
}
/**< �������ĸ� */

template<class T>
T Mytree<T>::GetRoot(Node<T>*tree)
{
	if (tree)
		return tree->value;
    else 
		return NULL;
}
/**< ����ɾ�� */

template<class T>
void Mytree<T>::clearTree(Node<T>* &tree)
{
    if(tree)
    { 
		
        clearTree(tree->lchild);   
        clearTree(tree->rchild);
		tree = NULL;
		delete tree;
    }
}
/**< �õ�����ĳ���ڵ��˫�� */
template<class T>
T Mytree<T>::GetParent(Node<T>*tree,T t)
{
 Node<T>*p = levelorder(tree,t);     //�õ��ڵ�t��λ��
 if(p!=NULL) return p->parent->value;
 else return NULL;
}
/**< �����ȸ����� */
template<class T>
Node<T>* Mytree<T>::levelorder(Node<T> *tree, T t)
{
	queue<Node<T>*> q;
	Node<T>*newtree =  new Node<T>;
	q.push(tree);
	while (!q.empty())
	{
		newtree = q.front();
		if (newtree->value == t)
			return newtree;
		q.pop();
		if (newtree->lchild)
			q.push(newtree->lchild);
		if (newtree->rchild)
			q.push(newtree->rchild);
	}
	return NULL;
}
/**< ɾ��������ĳ���ڵ������ */
template<class T>
void Mytree<T>::DeleteNode(Node<T>*tree,T t)
{
	Node<T>*p = levelorder(tree, t);
	if(p)
 {
     p->parent=NULL;
     clearTree(p);
 }
}
/**< ����������� */
template<class T>
void Mytree<T>::display(Node<T>* tree)
{
    if(tree)
    {
        cout<<tree->value<<" ";
        display(tree->lchild);
        display(tree->rchild);
    }
}

int main()
{
    cout << "���������������ʵ�֣�" << endl;
    Mytree<char> tree;
	Node<char> *mytree=new Node<char>;
    char t,s;
	tree.creatTree(mytree);
	tree.display(mytree);
	cout << endl;
    cout<<"���ĸ߶ȣ�"<<tree.getheight(mytree)<<endl;
	cout << "���ĸ���"<<tree.GetRoot(mytree)<<endl;
    cout<<"��t�ĸ���˫��:";
    cin>>t;
    cout<<tree.GetParent(mytree,t)<<endl;
    cout<<"ɾ�����ڵ�Ϊs��������";
    cin>>s;
    tree.DeleteNode(mytree,s);
	tree.display(mytree);
	getchar();
    return 0;
}
/*
���������������ʵ�֣�
a b d # # e # # c f # # #
���������������
a b d e c f
���ĸ߶ȣ�3
���ĸ���a
��t�ĸ���˫��:e
b
ɾ�����ڵ�Ϊs��������c
a b d e c




*/
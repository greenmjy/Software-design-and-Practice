#include<iostream>
#include<queue>
#include"mystack.h"
#include "mystack.cpp"

#include "myqueue.h"
#include "myqueue.cpp"

#define  Maxsize 20
using namespace std;

template<class T>
struct node
{
    node *lchild,*rchild;
    T data;
};

template<class T>
class Mytree
{
public:
 
    int creatTree(node<T> **tree);              //���������
    bool Isempty();                             //�ж��Ƿ�Ϊ��
    void  ClearTree(node<T> *tree);             //ɾ��������
    int GetTreeHight(node<T> *tree);            //���ض������ĸ߶�

    node<T> Lchild(node<T> *tree);              //���������
    node<T> Rchild(node<T> *tree);              //�����Ҷ���

    void Preorder(node<T> *tree);              //�ݹ�����ֱ���
    void Inorder(node<T> *tree);
    void Postorder(node<T> *tree);

    void Preorder1(node<T> *tree);               //�ǵݹ�����ֱ���
    void Inorder1(node<T> *tree);
    void Postorder1(node<T> *tree);

    void LevelOrder(node<T> *tree);              //�������

private:
    node<T> *tree;
};

template<class T>
int Mytree<T>::creatTree(node<T> **tree) 
{ //����������ʼ����
    T x;
    cin>>x;
    if(x<0)
    {
      *tree = NULL;
      return 0;
    }
    (*tree) = new node<T>;
    if(tree== NULL)
        return 0;
    (*tree)->data = x;
    creatTree(&(*tree)->lchild);
    creatTree(&(*tree)->rchild);
    return 1;
}

template<class T>
bool Mytree<T>::Isempty()
{
    return (!tree);
}

template<class T>
void Mytree<T>::ClearTree(node<T> *tree)
{
    if(!Isempty())
    {
       ClearTree(tree->lchild);
       ClearTree(tree->rchild);
       delete tree;
    }
}

template<class T>
int Mytree<T>::GetTreeHight(node<T> *tree)
{
    if(!tree)  return 0;
	
    int d1,d2;
    d1 = GetTreeHight(tree->lchild);
    d2 = GetTreeHight(tree->rchild);
    return (d1>d2?d1:d2)+1;
}

/*-----�������Ҷ���---------*/
template<class T>
node<T> Mytree<T>::Lchild(node<T> *tree)
{
    return tree->lchild->data;
}
template<class T>
node<T> Mytree<T>::Rchild(node<T> *tree)
{
    return tree->rchild->data;
}
/*-----�ݹ�����ֱ���-------*/
template<class T>
void Mytree<T>::Preorder(node<T> *tree)
{
	if (tree)
	{
		cout << tree->data << " ";
		Preorder(tree->lchild);
		Preorder(tree->rchild);
	}
}

template<class T>
void Mytree<T>::Inorder(node<T> *tree)
{
	if (tree){
		Inorder(tree->lchild);
		cout << tree->data << " ";
		Inorder(tree->rchild);
	}
}
template<class T>
void Mytree<T>::Postorder(node<T> *tree)
{
	if (tree)
	{
		Postorder(tree->lchild);
		Postorder(tree->rchild);
		cout << tree->data << " ";
	}
}
/*-----�ǵݹ�����ֱ���-----*/
template<class T>
void Mytree<T>::Preorder1(node<T> *tree)
{
 Mystack<node<T>*> s;
 node<T>*newtree = tree;
 while(newtree!=NULL||!s.IsEmpty())
 {
     while(newtree!=NULL)
     {
         cout<<newtree->data<<" ";
         s.Push(newtree);
         newtree = newtree->lchild;
     }
     if(!s.IsEmpty())
     {
		
		newtree = s.GetTop();
		s.Pop();
		newtree = newtree->rchild;
		 
     }
 }

}

template<class T>
void Mytree<T>::Inorder1(node<T> *tree)             //�ǵݹ�Ķ������������
{
    Mystack<node<T>*> s;
	node<T> *newtree = tree;
    s.MakeNull();
    while(newtree!=NULL||!s.IsEmpty())
    {
        if(newtree!=NULL)
        {
            s.Push(newtree);
            newtree = newtree->lchild;
        }
        else{
            newtree = s.GetTop();
			s.Pop();
            cout<<newtree->data<<" ";
           
            newtree = newtree->rchild;
        }
    }
}

template<class T>
void Mytree<T>::Postorder1(node<T>*tree)
{
    Mystack<node<T>*> s;
    node<T>*newtree = tree;
    node<T>*cur,*pre=NULL;
    s.Push(newtree);
    while(!s.IsEmpty())
    {
        cur = s.GetTop();
        if((cur->lchild==NULL&&cur->rchild==NULL)||(pre!=NULL&&(pre==cur->lchild||pre == cur->rchild)))
        {
            cout<<cur->data<<" ";
            s.Pop();
            pre = cur;
        }
        else
        {
            if(cur->rchild!=NULL)
               s.Push(cur->rchild);
            if(cur->lchild!=NULL)
                s.Push(cur->lchild);
        }
    }

}

/*-------------�������--------------*/
template<class T>
void Mytree<T>::LevelOrder(node<T> *tree)
{
 queue<node<T>*> q;
 node<T> *newtree = tree;
 if(newtree!=NULL)
    q.push(newtree);
 while(!q.empty())
 {
     newtree = q.front();
     q.pop();
	 cout << newtree->data << " ";
     if(newtree->lchild!=NULL)
        q.push(newtree->lchild);
     if(newtree->rchild!=NULL)
        q.push(newtree->rchild);
 }
}

int main()
{
    Mytree<int> tree;
    node<int> *root=new node<int>;
    cout<<"�������Ĺ��죺"<<endl;
    tree.creatTree(&root);
    cout<<"���ĸ߶ȣ�"<<tree.GetTreeHight(root)<<endl;
   
    cout<<"�ݹ�����ֱ�����"<<endl;
    cout<<"ǰ�������"<<endl;
    tree.Preorder(root);
    cout<<endl;
    cout<<"���������"<<endl;
    tree.Inorder(root); 
    cout<<endl;
    cout<<"���������"<<endl;
    tree.Postorder(root);
    cout<<endl;
    cout<<"�ǵݹ����ֱ�����"<<endl;
     cout<<"ǰ�������"<<endl;
     tree.Preorder1(root);
    cout<<endl;
    cout<<"���������"<<endl;
    tree.Inorder1(root);
    cout<<endl;
    cout<<"���������"<<endl;
    tree.Postorder1(root);
    cout<<endl;
    cout<<"���������"<<endl;
    tree.LevelOrder(root);
    cout<<endl;
	getchar();
	system("pause");
    return 0;
}
/*
�������Ĺ��죺
1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
���ĸ߶ȣ�3
�ݹ�����ֱ�����
ǰ�������
1 2 4 5 3 6
���������
4 2 5 1 6 3
���������
4 5 2 6 3 1
�ǵݹ����ֱ�����
ǰ�������
1 2 4 5 3 6
���������
4 2 5 1 6 3
���������
4 5 2 6 3 1
���������
1 2 3 4 5 6


*/
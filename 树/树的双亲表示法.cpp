/*����˫�ױ�ʾ��*/
#include<iostream>

#define MAX 100
using namespace std;

template<class T>
class node
{
public:
	T data;
	int parent;
};

template<class T>
class Tree
{
public:
	Tree()
	{
		Treenode = new node<T>[MAX];
	}
	~Tree()
	{
		delete []Treenode;
	}
	T GetParent(int);
	T GetLeftMostChild(int,int);
	T GetRightMostChild(int,int);
	T GetData(int);
	void CreatK(int);
	T GetRoot();
private:
	node<T> *Treenode;
};

template<class T>
void Tree<T>::CreatK(int n)
{
	cout << "�������Ľڵ㣬���丸�׵�λ�ã�" << endl;
	cout << "������ڵ㣺";
	cin >> Treenode[1].data;
	Treenode[1].parent = 0;
	for (int i = 2; i <= n; i++)
	{
		cin >> Treenode[i].data;
		cin >> Treenode[i].parent;
	}
}

template<class T>
T Tree<T>::GetParent(int i)
{
	int p = Treenode[i].parent;
	return Treenode[p].data;
}

template<class T>
T Tree<T>::GetData(int i)
{
	return Treenode[i].data;
}

template<class T>
T Tree<T>::GetRoot()
{
	return Treenode[1].data;
}

template<class T>
T Tree<T>::GetLeftMostChild(int i,int n) //���ȳ��ֵ�������ڵ㣬�����ֵ������ҽڵ�
{
	for (int k = 1; k <= n; k++)
	{
		if (Treenode[k].parent == i)
			return Treenode[k].data;
	}
	return NULL;//û������ڵ�
}

template<class T>
T Tree<T>::GetRightMostChild(int i, int n)
{
	int flag = 0,j;
	for (int k = n; k > 0; k--)
	{
		if (Treenode[k].parent == i)
		{
			for (j = k - 1; j > 0; j--)
			{
				if (Treenode[j].parent == i)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1) return Treenode[k].data;
		}
	}
	return NULL;//û�����ҽڵ�
}
//����
int main()
{
    cout<<"����˫�ױ�ʾ��"<<endl;
	Tree<char> newtree;
	int n;
	cout << "�������ڵ���Ŀ��";
	cin >> n;
	newtree.CreatK(n);
	cout << "��û�ж�Ӧ�����������ʾû��" << endl;
	cout << "�������ڵ������ֵ��" << newtree.GetData(3) << endl;
	cout << "�������ڵ�������������ڵ�ֵ��" << newtree.GetLeftMostChild(3, n) << endl;
	cout << "�������ڵ�������������ڵ�ֵ��" << newtree.GetRightMostChild(3, n) << endl;
	cout << "�������ڵ�ĸ��׽ڵ�ֵ��" << newtree.GetParent(3) << endl;
	cout << "���ڵ�ֵ��" << newtree.GetRoot() << endl;
	getchar();
	return 0;
}
/*
����˫�ױ�ʾ��
�������ڵ���Ŀ��7
�������Ľڵ㣬���丸�׵�λ�ã�
������ڵ㣺a
b 1
c 2
d 1
e 4
f 3
g 2
��û�ж�Ӧ�����������ʾû��
�������ڵ������ֵ��c
�������ڵ�������������ڵ�ֵ��f
�������ڵ�������������ڵ�ֵ��

*/



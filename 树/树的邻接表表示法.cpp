#include<iostream>
#define MAX 100
using namespace std;
template<class T>
class  node
{
public:
	node()
	{
		next = NULL;
		Treelist = new T[MAX];
	}
	~node()
	{
		delete[]Treelist;
	}
	T data;
	T *Treelist;
	node *next;
};

template<class T>
class Tree
{
public:
	Tree()
	{
		head = new node<T>[MAX];
	}

	~Tree()
	{
		delete []head;
	}
	void Creat(int);
	T GetLeftMostChild(int);
	T GetRightMostChild(int);
	T GetData(int);
	T GetParent(int);
	T GetRoot();
private:
	node<T> *head;
};

template<class T>
void Tree<T>::Creat(int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "�����" << i << "���ڵ㣺";
		cin >> head[i].data;
		cout << "�����������ĸ�����";
		int m;
		cin >> m;
		if (m == 0) continue;
		cout << "������������";
		head[i].Treelist[0] = head[i].data;
		for (int j = 1; j <= m; j++)
			cin >> head[i].Treelist[j];
	}
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << head[i].data << "->";
		int j = 1;
		while (head[i].Treelist[j] > 0)
		{
			cout << head[i].Treelist[j] << " ";
			j++;
		}
		cout <<  endl;
	}
}

template<class T>
T Tree<T>::GetLeftMostChild(int i)
{
	if (head[i].Treelist[0] > 0 && head[i].Treelist[1] > 0)
		return head[i].Treelist[1];
	else return NULL;
}

template<class T>
T Tree<T>::GetRightMostChild(int i)    
{
	int flag = 0;
	for (int j = 2;; j++)
	{
	if (head[i].Treelist[0] < 0||head[i].Treelist[1]<0) return NULL;
		if (head[i].Treelist[j]<0)
		{
			flag = 1;
			if (j == 2) return NULL;
			return head[i].Treelist[j - 1];
		}
	}
	if(flag==0) return NULL;
}

template<class T>
T Tree<T>::GetData(int i)
{
	return head[i].data;
}

template<class T>
T Tree<T>::GetRoot()
{
	return head[1].data;
}

template<class T>
T Tree<T>::GetParent(int i)
{
	for (int j = 1; j < i; j++)
	{
		for (int k = 1; head[j].Treelist[k] != NULL; k++)
		{
			if (head[i].data == head[j].Treelist[k])
			{
				return head[j].data;
			}
		}
	}
	return NULL;
}
int main()
{
	Tree<int> newtree;
	int n;
	cout << "�����ڽӱ��ʾADT��Ĭ����������ֶ�Ϊ��0�������" << endl;
	cout << "�������ڵ���Ŀ��";
	cin >> n;
	newtree.Creat(n);
	cout << "�õ���Ϊ0��ʾû�з���Ҫ���" << endl;
	cout << "���ĸ��ڵ㣺" << newtree.GetRoot() << endl;
	cout << "��2���ڵ�����ݣ�" << newtree.GetData(2) << endl; //2��Ϊ�������������Ը���
	cout << "��2���ڵ�ĸ��ף�" << newtree.GetParent(2) << endl;
	cout << "��2���ڵ������������" << newtree.GetLeftMostChild(2) << endl;
	cout << "��2���ڵ������������" << newtree.GetRightMostChild(2) << endl;
	getchar();
	return 0;
}

/*
������������6 7
�����4���ڵ㣺4
�����������ĸ�����0
�����5���ڵ㣺5
�����������ĸ�����0
�����6���ڵ㣺6
�����������ĸ�����0
�����7���ڵ㣺7
�����������ĸ�����0

1->2 3 4
2->5
3->6 7
4->
5->
6->
7->
�õ���Ϊ0��ʾû�з���Ҫ���
���ĸ��ڵ㣺1
��2���ڵ�����ݣ�2
��2���ڵ�ĸ��ף�1
��2���ڵ������������5
��2���ڵ������������0

*/
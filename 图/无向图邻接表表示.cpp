#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<queue>
#define NUM 100

using namespace std;

bool visited[NUM];    //������Ϣ

struct node  //�ڽӱ�-���Ա�
{
	int  index;          //�ڽӶ���ı��
	struct node *next;   //��һ���߽ڵ�
};

template<class T>
struct vnode{
	T adjvex;          //����������
	struct node *fp;    //ָ���һ���߽ڵ� 
};

template<class T>
class  Agraph      //ͼA�Ķ����
{
public:
	vnode<T>  alist[NUM];
	int n, e;
};

template<class T>
class graph
{
public:
	void creatAfraph();

	void dfs();
	void Dfs(int i);
	void bfs();
	void Bfs(int k);
private:
	Agraph<T> A;
};

template<class T>
void graph<T>::creatAfraph()
{
	srand((unsigned)time(NULL));
	cout << "������ͼ�Ķ�������";
	cin >> A.n;
	cout << "������ͼ�ı�����";
	cin >> A.e;
	int i, j, k;
	for (i = 0; i < A.n; i++)
	{ 
		A.alist[i].adjvex = i;    //���붥���������
		A.alist[i].fp = NULL;
	}
	for (k = 0; k < A.e; k++)
	{
		cout << "���� i,j(0~n-1)��i��j�����ӣ�:" << endl;
		cin >> i >> j;
		node* s = new node;
		s->index = j;
		s->next = A.alist[i].fp;
		A.alist[i].fp = s;
	}
}
template<class T>
void graph<T>::dfs()                  //�ڽӱ�洢ͼ���������
{
	int i;
	for (i = 0; i < A.n; i++)
	{
		visited[i] = false;
	}
	cout << "�ڽӱ�洢ͼ���������" << endl;
	for (i = 0; i < A.n; i++)
	{
		if (visited[i] == false)
			Dfs(i);
	}
	cout << endl;
}

template<class T>
void graph<T>::Dfs(int i)
{
	node *p;
	cout << A.alist[i].adjvex;
	visited[i] = true;
	p = A.alist[i].fp;
	while (p)
	{
		if (!visited[p->index])
			Dfs(p->index);
		p = p->next;
	}
}
template<class T>
void graph<T>::bfs()           //�ڽӱ�洢ͼ���ȹ����
{
	int i;
	for (i = 0; i < A.n; i++)
	{
		visited[i] = false;
	}
	cout << "�ڽӱ�洢ͼ���ȹ����" << endl;
	for (i = 0; i < A.n; i++)
	{
		if (visited[i] == false)
			Bfs(i);
	}
}
template<class T>
void graph<T>::Bfs(int k)
{
	int i;
	queue<int>q;
	node *p;
	p = NULL;
	if (!q.empty()) return;
	cout << A.alist[k].adjvex;
	visited[k] = true;
	q.push(k);

	while (q.empty() == false)
	{
		i = q.front();
		q.pop();
		p = A.alist[i].fp;
		while (p)
		{
			if (!visited[p->index])
			{
				cout << A.alist[p->index].adjvex;
				visited[p->index] = true;
				q.pop();

			}
			p = p->next;
		}
	}

}
int main()                //��visual studio 2013����ʱ����ʹ�ö��Ե�ʱ������ڵ�һЩ��ͻ��û�ҵ����������
{                         //��ѡ�����,���������ó��ȹ�����Ľ��
	graph<int> T;
	T.creatAfraph();
	T.dfs();
	T.bfs();
	return 0;
}
/*
������ͼ�Ķ�������4
������ͼ�ı�����5
���� i,j(0~n-1)��i��j�����ӣ�:
0 1
���� i,j(0~n-1)��i��j�����ӣ�:
0 3
���� i,j(0~n-1)��i��j�����ӣ�:
1 2
���� i,j(0~n-1)��i��j�����ӣ�:
1 3
���� i,j(0~n-1)��i��j�����ӣ�:
2 3
�ڽӱ�洢ͼ���������
0312
�ڽӱ�洢ͼ���ȹ����
0312



*/
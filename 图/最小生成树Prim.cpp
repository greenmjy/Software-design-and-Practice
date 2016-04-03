
// Prim�㷨ʵ�֣������ڽӱ�洢��
//

#include<iostream>

using namespace std;

#define MAX 100
#define Infinity 65535

template<class T>
struct edgeNode
{
	int no; //�߶˵����
	T info; //�߶˵�����
	int weight; //�ߵ�Ȩֵ
	struct edgeNode * next; //��һ��
};

template<class T>
struct vexNode
{
	T info;  //�ڵ�����
    edgeNode<T> *link; //��֮�����Ķ˵�
};


template<class T>
class Prim
{
public:
	bool visited[MAX];        //���ʱ�־
	void creatGraph(int, int, int);
	 void primTree(int,int,int);
private:
	vexNode<T> adjlist[MAX]; //�洢�ڵ���Ϣ
	int lowcost[MAX];        //lowcost[j]�洢�ӿ�ʼ�ڵ㵽�ڵ�j����С����
	int parent[MAX];          //parent[j]��ʾ�ڵ�j��ǰ���ڵ�
};


//�����ڽӱ�洢
template<class T>
void Prim<T>::creatGraph(int n, int e, int v0)//�ӵ�V0���ڵ㿪ʼ����
{
	for (int i = 1; i <= n; i++)
	{
		cout << "������ڵ�" << i << "�����ƣ�";
		cin >> adjlist[i].info;
		adjlist[i].link = NULL;
		//��ʼ��
		visited[i] = false;
		lowcost[i] = Infinity;
		parent[i] = v0;
	}
	edgeNode<T> *p1, *p2;
	int v1, v2;       
	int weight;
	for (int i = 1; i <= e; i++)
	{
		cout << "�������" << i << "�Ķ��˵Ľڵ���ţ�";
		cin >> v1 >> v2;
		cout << "�˱ߵ�Ȩֵ��";
		cin >> weight;
		p1 = new edgeNode<T>;
		p2 = new edgeNode<T>;

		p1->no = v1;
		p1->weight = weight;
		p1->info = adjlist[v1].info;
		p1->next = adjlist[v2].link;
		adjlist[v2].link = p1;
		p2->no = v2;
		p2->weight = weight;
		p2->info = adjlist[v2].info;
		p2->next = adjlist[v1].link;
		adjlist[v1].link = p2;
	}
}

template<class T>
void Prim<T>::primTree(int n, int e, int v)
{
	int sum = 0;     //��������Ȩֵ
	edgeNode<T> *p, *q;
	p = adjlist[v].link;
	visited[v] = true;
	while (p != NULL)
	{
		lowcost[p->no] = p->weight;
		p = p->next;
	}
	int minCost;
	for (int i = 1; i<n; i++)
	{
		minCost = Infinity;
		int k;
		for (int j = 1; j <= n; j++)
		{
			if (minCost>lowcost[j] && !visited[j])
			{
				minCost = lowcost[j];
				k = j;
			}
		}
		sum += minCost;
		visited[k] = true;
		q = adjlist[k].link;
		while (q != NULL)
		{
			if (!visited[q->no] && q->weight < lowcost[q->no])
			{
				lowcost[q->no] = q->weight;
				parent[q->no] = k;
			}
			q = q->next;
		}
	}
	cout << "��С�������ı�Ϊ��" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (i != v)
			cout << "(" << adjlist[parent[i]].info << "," << adjlist[i].info << ")" << " ";
	}
	cout << endl;
	cout << "��С��������ȨֵΪ��" << sum << endl;

}

int main( )
{
	Prim<int> prim;
	int n, e;
	cout << "������ڵ�����";
	cin >> n;
	cout << "�����������";
	cin >> e;
	cout << "���������һ���ڵ㿪ʼ��";
	int v;
	cin >> v;
	prim.creatGraph(n, e, v);
	prim.primTree(n, e, v);
	
	system("pause");
	return 0;
}
/*
����ڵ�����5
������6
��ʼ�ڵ㣺1
�ڵ����ƣ�1 2 3 4 5 
��������ż�Ȩֵ��
1 2 1
1 3 2
1 4 3
2 5 4
3 5 5
3 4 6
�����
��С�������ߣ�<1,2> <1,3> <1,4> <2,5>
��С��������Ȩֵ��10

*/
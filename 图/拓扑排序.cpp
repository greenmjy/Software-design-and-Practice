/*��������*/

#include<iostream>
#include<queue>
using namespace std;

#define Max 20

template<class T>
struct node
{
	T data;          //ͼ��������
	int next[Max];     //����ͼ����ָ�����һ�ڵ����
	int indegree;   //���
};

template<class T>
class Graph
{
public:
	Graph()
	{
		for (int i = 1; i <= Max; i++)
		{
			adjlist[i].indegree = 0;
		}

	}
	void creatGraph(int);
	void TopoOrder(int);
private:
	node<T> adjlist[Max];
};

template<class T>
void Graph<T>::creatGraph(int n)
{
	int outdegree;
	int num;
	for (int i = 1; i <= n; i++)
	{
		cout << "�����" << i << "�����㣺";
		cin >> adjlist[i].data;
		cout << "����˽ڵ���ȣ�";
		cin >> outdegree;
		if (outdegree == 0) continue;
		cout << "����˽ڵ�ָ�������Ķ������ţ�";
		for (int j = 1; j <= outdegree; j++)
		{
			cin >> num;
			adjlist[i].next[j] = num;
			adjlist[num].indegree++;
		}
	}

}

template<class T>
void Graph<T>::TopoOrder(int n)
{
	queue<T> q;
	int v, w;
	T lin;
	int nodecount;
	for (v = 1; v <= n; v++)
	{
		if (adjlist[v].indegree == 0)
		{
			q.push(adjlist[v].data);
		}
	}
	nodecount = 0;
	v = 1;
	while (!q.empty())
	{

		if (v > n) break;
		lin = q.front();
		q.pop();
		cout << lin << " ";
		nodecount++;  //����������
		for (w = 1; adjlist[v].next[w]>=0&&adjlist[v].next[w]<=Max; w++) //�ٽ���v��ÿ������w
		{
			int temp = adjlist[v].next[w]; //��v�����Ľڵ����
			adjlist[temp].indegree--;      //ɾ��v�����ı�
			if (adjlist[temp].indegree == 0)
				q.push(adjlist[temp].data);
		}
		v++;
	}
		if (nodecount < 0)
			cout << "����ͼ���ڻ�·" << endl;

}

int main()
{
	Graph<char> graph;
	int n;
	cout << "��������ͼ��"<<endl;
	cout << "����ͼ�Ķ��������";
	cin >> n;
	graph.creatGraph(n);
	cout << "��������" << endl;
	graph.TopoOrder(n);  //��������
	//getchar();
	return 0;
}
/*
���붥�㣺5
��һ�����㣺a ���ȣ�2  ָ�������������ţ�2 3
b 1 4
c 1 5
d 1 5
e 0
�����
a b c d e

���룺5
*/

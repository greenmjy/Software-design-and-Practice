/*�ڽӾ����ʾͼ������������ȹ����*/
#include <iostream>
#include<ctime>
#include<stdlib.h>
#include<queue>

#define numV 100                 //������
#define numE 100                 //����

using namespace std;
         

bool visited[numV];            //���ʱ������
int  dfn[numV];                //�����������
//int  count;                    //������
template<class T>
struct MGraph
{
	T Vlist[numV];           //�����
	int edge[numE][numE];    //�ڽӾ���
};
template<class T>
class Graph
{
public:
	void CreatGraph();      //�ڽӾ�������ͼ
	void outGraph();        //����ڽӾ���
	void DFST();            //�������
	void DFS_1(MGraph<T>, int);   //�������֮�ڽӾ����ʵ��
	void BFST();           //�ȹ����
	void BFS_1(MGraph<T>, int);     //�ȹ����֮�ڽӾ����ʵ��
private:
	int count;
	MGraph<T> G;
	int n;                 //��ǰ����ĸ���

};

template<class T>
void Graph<T>::CreatGraph()
{
	srand((unsigned)time(NULL));
	int j;
	cout << "���������붥������";
	cin >>n;                   //���붥����
	for (int i = 0; i <n; i++)      //���붥����Ϣ�����������
	{
		cout << "�����" << i+1 << "������ ";
		cin >> G.Vlist[i];                        
	}
	cout << endl;
	for (int i = 0; i <n; i++)
	{
		for (j = i; j <n; j++)
		{
			if (i == j) G.edge[i][j] = 0;
			else G.edge[i][j] = rand() % 2;        //��������ڽӾ���
			G.edge[j][i] = G.edge[i][j];
		}
	}
}

template<class T>
void Graph<T>::outGraph()      //�ڽӾ�������
{
	cout << "��������ڽӾ�������" << endl;
	int i, j;
	int n1;
	n1 = n;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			cout << G.edge[i][j] << " ";
		}
		cout << endl;
	}
}

template<class T>
void Graph<T>::DFST()
{
	int i;
	count = 0;
	for (i = 0; i < n; i++)           //���ʱ������ĳ�ʼ��
	{
		visited[i] = false;
	}
	cout << "��������Ľ����" << endl;
	for (i = 0; i <n; i++)
	{
		if (!visited[i])
		{

			DFS_1(G, i);   //��������

		}
	}
	cout << endl;
}
template<class T>
void Graph<T>::DFS_1(MGraph<T> G, int i)     //���ڽӾ��������������
{
	int j;
	cout << G.Vlist[i] << " ";
	visited[i] = true;                 //����ѷ��ʵ�
	dfn[i] = count++;                  //�����������
	for (j = 0; j <n; j++)
	{
		if ((G.edge[i][j] == 1) && (visited[j] == false))
			DFS_1(G, j);
	}
}
template<class T>
void Graph<T>::BFST()
{
	int i;
	for (i = 0; i < n; i++)           //���ʱ������ĳ�ʼ��
	{
		visited[i] = false;
	}
	cout << "�ȹ�����Ľ����" << endl;
	for (i = 0; i < n; i++)
	{

		if (visited[i] == false)
		{
			BFS_1(G, i);          //�ȹ�����
		}
	}
	cout << endl;
}

template<class T>
void Graph<T>::BFS_1(MGraph<T> G, int k)    //�ȹ����� �ӵ�k�Ŷ��㿪ʼ 
{
	int  j;
	queue<int> Q;
	Q.push(k);
	while (!Q.empty())
	{

		k = Q.front();
		if (!visited[k]) cout << G.Vlist[k] << " ";
		visited[k] = true;
		Q.pop();
		for (j = 0; j < n; j++)
		{
			if (G.edge[k][j] == 1 && visited[j] == false)
			{
				Q.push(j);
			}
		}
	}
}


int main()
{
	Graph<char> T;                       //Ӧ��֮ǰд��������ɵ��ڽӾ��󣬸ĳ���ģ����
	T.CreatGraph();
	T.outGraph(); 
	T.DFST();
	T.BFST();
	return 0;
}
/*
���������붥������6
�����1������ a
�����2������ b
�����3������ c
�����4������ d
�����5������ e
�����6������ f

��������ڽӾ�������
0 0 0 1 0 0
0 0 1 0 1 0
0 1 0 1 0 1
1 0 1 0 1 1
0 1 0 1 0 1
0 0 1 1 1 0
��������Ľ����
a d c b e f
�ȹ�����Ľ����
a d c e f b
*/
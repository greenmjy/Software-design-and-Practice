/*��С������kruskal�㷨*/

#include<iostream>

#define maxn 20
using namespace std;
template<class T>
class edgenode
{
public:
	int first;//�ߵ���㶥�����
	int next; //���յ㶥�����
	int weight;//�ߵ�Ȩֵ

};

template<class T>
class Kruskal
{
public:
	void kruskal();
	void creatGraph();
	void weightOrder();//��Ȩֵ�����
	void kruskalTree();
	bool judge(int,int);
private:
	T adj[maxn];      //�����
	int n, e;         //������������
	edgenode<T> edge[maxn];
	int tree[maxn];
};

template<class T>
void Kruskal<T>::kruskal()
{
	for (int i = 1; i <= maxn; i++)
	{
		tree[i] = -1;//��ʼ����Ϊ-1
	}
}
template<class T>
void Kruskal<T>::creatGraph()
{
	cout << "���붥����Ŀ��";
	cin >> n;
	cout << "�����������";
	cin >> e;
	cout << "���붥�㣺";
	for (int i = 1; i <= n; i++)
		cin >> adj[i];
	cout << "�������㶥����ţ��յ㶥����ţ�Ȩֵ��"<<endl;
	for (int i = 1; i <= e; i++)
	{
		cin >> edge[i].first >> edge[i].next >> edge[i].weight;
		//tree[edge[i].next] = edge[i].first;  //�յ�ĸ��������
	}
}

template<class T>
void Kruskal<T>::weightOrder()//ϣ�����򽫱߰�Ȩֵ��С��������
{
	for (int i = 1; i <= e; i++)
	{
		int j = i;
		while (edge[j].weight < edge[i].weight)
		{
			edgenode<T> *p = new edgenode<T>;
			*p = edge[i];
			edge[i] = edge[j];
			edge[j] = *p;
			j--;
		}
	}
}
template<class T>
bool Kruskal<T>::judge(int first, int next)
{
	if (tree[first] != -1 && tree[next] != -1)
		return false;//��û�и���
	while (tree[first] != -1)
		first = tree[first];
	while (tree[next] != -1)
		next = tree[next];
	if (first == next)
		return true;
	return false;
}

template<class T>
void Kruskal<T>::kruskalTree()
{
	int j = 1;
	for (int i = 1; i < n; i++,j++)  //n-1����
	{
		
		if (judge(edge[j].first, edge[j].next))
		{
			i--;
			continue;
		}
		int first = edge[j].first;
		int next = edge[j].next;
		while (tree[first] != -1)
			first = tree[first];
		tree[first] = next;
		//edge[i].first = first;
		//edge[i].next = next;
	}
	int sum = 0;//Ȩֵ
	for (int i = 1; i < n; i++)
	{
		if (tree[i] == -1)
			continue;
		cout << "(" << adj[edge[i].first] << "," << adj[edge[i].next] << ")";
		sum += edge[i].weight;
	}
	cout << "��Ȩֵ��" << sum << endl;
}

int main()
{
	Kruskal<char> k;
	k.kruskal();
	k.creatGraph();
	k.weightOrder();
	k.kruskalTree();
	getchar();
	return 0;
}
/*
���붥����Ŀ��5
�����������6
���붥�㣺a b c d e
�������㶥����ţ��յ㶥����ţ�Ȩֵ��
1 2 1
1 3 2
1 4 3
2 5 4
3 5 5
3 4 6
�����
(a,b)(a,c)(a,d)(b,e)��Ȩֵ��10


*/

#include<iostream>
#define Max 30  //ͼ����󶥵���
#define inital 65535
using namespace std;

template<class T>
class Dijkstra
{
public:
	Dijkstra()
	{
		for (int i = 1; i <= Max; i++)
		for (int j = 1; j <= Max; j++)
		{
			if(i==j) 
				GraphC[i][j] = 0;
			else 
				GraphC[i][j] = inital;
		}
	}
	void creatGraph(int,int);
	void dijkstraTree(int);
	void Floyd(int);
private:
	int GraphC[Max][Max];//�ڽӾ���
	T adjlist[Max];  //�洢����
	T mark[Max];  //��ǰ���㼯��
	int D[Max];//�洢��ǰ�㵽Դ��ļ���

	int A[Max][Max];   //Floyd�洢�����������·���ľ���
};

template<class T>
void Dijkstra<T>::creatGraph(int n,int e)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "�����" << i << "�����㣺";
		cin >> adjlist[i];
	}
	int x, y, w;
	for (int k = 1; k <= e; k++)
	{
		cout << "�����" << k << "����(i->j,Ȩֵw)��";
		cin >> x >> y >> w;
		GraphC[x][y] =w;

	}
	cout << "����ͼ���ڽӾ���" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << GraphC[i][j] << '\t';
		cout << endl;
	}
}

template<class T>
void Dijkstra<T>::dijkstraTree(int n)
{
	int i, j, min, pos;
	for (i = 1; i <= n; i++)
	{
		mark[i] = 0;//û�е����
		D[i] = GraphC[1][i];//D�ó�ֵ
	}
	mark[1] = 1;//Դ��1����
	D[1] = 0;
	for (int k = 1;k <= n;k++)
	{
		min = inital;
		for (j = 1; j <= n; j++)
		{
			if ((!mark[j]) && D[j] < min)
			{//ȡ������V�е���С��w
				min = D[j];
				pos = j;
			}
		}
		if (min == inital)
			break;
		mark[pos] = 1;
		for (j = 1; j <= n; j++)
		{
			if (!mark[j] && (D[j] > D[pos] + GraphC[pos][j]))
				D[j] = D[pos] + GraphC[pos][j];
		}
	}
	cout << "���Դ��1��������������·����" << endl;
	for (i = 1; i <= n; i++)
		cout << "1->" << i << " :" << D[i] << endl;
}

template<class T>
void Dijkstra<T>::Floyd(int n)
{
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			A[i][j] = GraphC[i][j];//A�ĳ�ֵ
		}
	}
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if ((A[i][k] + A[k][j]) < A[i][j])
				{
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
	}
	cout << "������������֮�����·������A��" << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << A[i][j] << '\t';
		cout << endl;
	}
}
int main()
{
	int n,e;
	Dijkstra<int> dijtree;
	cout << "����ͼ�Ķ�������";
	cin >> n;
	cout << "����ͼ��������";
	cin >> e;
	dijtree.creatGraph(n,e);
	cout << "��Դ���·��Dijkstra�㷨" << endl;
	dijtree.dijkstraTree(n);
	cout << "��Դ���·��Floyd�㷨��" << endl;
	dijtree.Floyd(n);
	getchar();
	return 0;
}
/*
���룺5 7
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
�����
Dijkstra:
1->1  0
1->2  10
1->3 50
1->4 30
1->5  60
floyd
0       10      50      30      60
65535   0       50      65535   60
65535   65535   0       65535   10
65535   65535   20      0       30
65535   65535   65535   65535   0
*/
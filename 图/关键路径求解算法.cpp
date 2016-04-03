#include<iostream>
#include<stack>
#define Max 30 //ͼ��󶥵���������
using namespace std;
template<class T>
struct edgenode
{ //�߱�
	int adjvex;
	int weight;
	struct edgenode<T> *nextedge;
};

template<class T>
struct vexnode
{//�����
	T vex;
	int indegree;
	struct edgenode<T> *firstedge;
};

template<class T>
class AOE
{
public:
	
	void CreatAoe();       //����AOE��������ͼ
	void TopSort();        //����������������緢��ʱ�估��������
	void KeyPath();        //�ؼ�·����ɵ�ͼ
private:
	vexnode<T> vex[Max];
	int n, e;
	T adj[Max];  //�洢ͼ�Ķ���
	int ve[Max], vl[Max]; //���緢��ʱ�����ٷ���ʱ��
	int tuopu_arr[Max];  //������������Ľڵ����
};


template<class T>
void AOE<T>::CreatAoe()
{
	cout << "����AOE����"<<endl;
	cout << "���붥�������";
	cin >> n;
	cout << "�����������";
	cin >> e;
	cout << "����AOE���Ķ��㣺";
	for (int i = 0; i < n; i++)
	{
		cin >> vex[i].vex;
		vex[i].firstedge = NULL;//��ʼ��Ϊ��
	}
	int a, b, w;
	for (int j = 0; j < e; j++) 
	{
		edgenode<T> *p=new edgenode<T>;
		cout << "����i,j��i->j��Ȩֵw:";
		cin >> a >> b >> w;
		p->adjvex = b-1;
		p->weight = w;
		p->nextedge = vex[a-1].firstedge;
		vex[a-1].firstedge = p;  //ͷ�巨
	}
}
template<class T>
void AOE<T>::TopSort()
{
	stack<T> s;
	edgenode<T> *p;

	int count = 0;
	int i;
	for (i = 0; i < n; i++)
		vex[i].indegree = 0;            //��ʼ�����Ϊ0
	for (i = 0; i < n; i++)
	{
		p = vex[i].firstedge;
		while (p)
		{
			vex[p->adjvex].indegree++;  //��ȼ�һ
			p = p->nextedge;
		}
	} 
	for (i = 0; i < n;i++)
	   if (vex[i].indegree == 0)
		   s.push(i);          //��Ϊ0�Ķ��������ջ
	for (i = 0; i < n; i++)
		ve[i] = 0;//��ʼ�������¼������緢��ʱ��
	while (!s.empty())
	{
		i = s.top();
		tuopu_arr[count] = i;//���������������
	    s.pop();
		cout << vex[i].vex << " ";//ջ��Ԫ�����
		count++;
		p = vex[i].firstedge;
		while (p)
		{
			int k, weight;
			weight = p->weight;
			k = p->adjvex;
			vex[k].indegree--;//ɾ����
			if (vex[k].indegree == 0)
			{
				s.push(k);
			}
			
			if (ve[i] + weight > ve[k])
				ve[k] = ve[i] + weight;  //���㶥�������ڽӵ�����緢��ʱ��
			p = p->nextedge;
			if (count >= n)  break;
		}
	}
	if (count < n) cout << "�л�·" << endl;
}
template<class T>
void AOE<T>::KeyPath()
{
	int i, j,m, weight;
	int ee, el;
	edgenode<T>*p;
	cout << "������������" <<endl;
	TopSort();
	cout << endl;
	for (i = 0; i < n; i++)
		vl[i] = ve[n - 1];//��ʼ��
	
	for (i = 0; i < n; i++)
	{
		int k = tuopu_arr[n - 1 - i];//���˵�����
		for (p = vex[k].firstedge; p; p = p->nextedge)
		{
			m = p->adjvex;
			weight = p->weight;
			if (vl[m] - weight < vl[k])
				vl[k] = vl[m] - weight;
		}
	}
	int k;
	for (i = 0; i < n; i++)
	{
		for (p = vex[i].firstedge; p; p = p->nextedge)
		{
			 k = p->adjvex;
			weight = p->weight;
			ee = ve[i];
			el = vl[k] - weight;
		}
		if (ee == el)
			if(vex[i].vex!=vex[k].vex)cout << "(" << vex[i].vex << "->" << vex[k].vex << ") ";
	}
}
int main()
{
	AOE<char> aoe;
	aoe.CreatAoe();
	aoe.KeyPath();
	getchar();
	system("pause");
	return 0;
}
/*
��������9
������11
���㣺a b c d e f g h i
i j Ȩֵ��
1 2 6
1 3 4
1 4 5
2 5 1
3 5 1
4 6 2
5 7 9
5 8 7
6 8 4
7 9 2
8 9 4
�����
������������a b c e g d f h i
(a->b) (b->e) (e->g) (g->i) (h->i) 

*/
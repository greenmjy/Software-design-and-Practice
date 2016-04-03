/*�ȼ���Ļ���*/
#include<iostream>
#define Max 100
using namespace std;
class node
{
public:
	node()
	{
		father = count = 0;
	}
	int father;
	int count;
};

class MFEST
{
public:
	MFEST()
	{
		arr = new node[Max];
	}

	~MFEST(){
		delete[]arr;
	}
	void Initial(int);
	void Union(int, int);
	int Find(int);
	void EQUIVA(int);
private:
	node *arr;
};

void MFEST::Initial(int i)
{
	arr[i].count = 1;
	arr[i].father = 0;
}

void MFEST::Union(int a, int b)
{
	if (arr[a].count > arr[b].count)
	{
		arr[b].father = a;
		arr[a].count += arr[b].count;
	}
	else
	{
		arr[a].father = b;
		arr[b].count += arr[a].count;
	}
	cout << "����ɹ���" << endl;
}


int MFEST::Find(int i)
{
	int f = i;
	while (arr[f].father != 0)
		f = arr[f].father;
	return f;
}

void MFEST::EQUIVA(int n)
{
	int i, j, k, m;
	for (i = 1; i < n + 1; i++)
		Initial(i);//����iֻ����Ԫ��i
	cout << "����ȼ۶ԣ�0 0��������" << endl;
	cin >> i >> j;
	while (!(i == 0 && j == 0))
	{
		k = Find(i); //i��j�ĸ�
		m = Find(j);
		if (k != m)   //i �� j ����һ������
			Union(i, j);
		else cout << "i��j�Ѿ���һ�����ϣ����úϲ�" << endl;
		cin >> i >> j;
	}
}

int main()
{
	 MFEST mfe;          
	mfe.Initial(1);
	cout << "���ϸ�����";
	int n;
	cin >> n;
	mfe.EQUIVA(n);
	int b;
	cin >> b;
	cout<<"b���������ڵ㣺"<<mfe.Find(b);
	return 0;
}


/*
���ϸ�����5
����ȼ۶ԣ�0 0��������
1 3
����ɹ���
3 4
����ɹ���
4 6
����ɹ���
5 4
����ɹ���
3 6
i��j�Ѿ���һ�����ϣ����úϲ�
3 5
i��j�Ѿ���һ�����ϣ����úϲ�
0 0
5
b���������ڵ㣺3

*/
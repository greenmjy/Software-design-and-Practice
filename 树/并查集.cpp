/*���鼯*/
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
	void Union(int,int);
	int Find(int);
private:
	node *arr;
};

void MFEST::Initial(int i)
{
	arr[i].count = 1;
	arr[i].father = 0;
}

void MFEST::Union(int a,int b)
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

int main()                  
{
	MFEST mfe;
	int i = 1;
	mfe.Initial(i);
	int a = 10,b=0;
	cout << "���벢���ֵ��" << endl;
	while (b != -1)
	{
		cin >> b;
		mfe.Union(b,a);
	}
	cout << "����b��";
	cin >> b;
	cout<< mfe.Find(b) << endl;
	return 0;
}
/*
���벢���ֵ��
12
����ɹ���
9
����ɹ���
0
����ɹ���
1
����ɹ���
-1
����ɹ���
����b��9
1


*/
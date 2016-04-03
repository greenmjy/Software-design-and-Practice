/*����洢�ṹ��������㷨
ʵ�� �������ʱ�Ĺ���*/
#include <iostream>
#define Max 20
using namespace std;
template<class T>
struct rate
{
	T date[Max];
	char name[Max];
};

template<class T>
class bank{
public:
	bank();
	~bank();
	void input(int n);               //����
	void insert(int banklist, int n);//����
	void deletel(int banklist, int n);//ɾ��
	void output(int n);               //���
private:
	rate<T> *b;
	int count;
};

template<class T>
bank<T>::bank()
{
	b = new rate<T>[Max];
	count = 0;
}

template<class T>
bank<T>::~bank()
{
	delete[]b;
}

template<class T>
void bank<T>::input(int n)
{
	count = n;
	for (int i = 0; i<n; i++)
	{
		cout << "�������֣�";
		cin >> b[i].name;
		cout << "�������ʣ�";
		for (int j = 0; j<5; j++)
			cin >> b[i].date[j];
	}
}

template<class T>
void bank<T>::insert(int banklist, int n)
{
	rate<T> *p = new rate<T>;
	for (int i = count - 1; i >= banklist; i--)
		b[i + 1] = b[i];
	cout << "�����������֣�";
	cin >> p->name;
	cout << "�������ʣ�";
	for (int i = 0; i < 5; i++)
		cin >> p->date[i];
	b[banklist] = *p;
	count++;                    //nֵ����1
}

template<class T>
void bank<T>::deletel(int banklist, int n)
{
	for (int i = banklist; i < count; i++)
		b[i] = b[i + 1];        //���Ǽ�ɾ��
	count--;
}

template<class T>
void bank<T>::output(int n)
{
	cout << "name \t" << "3 months \t" << "6 months \t" << "1 year\t\t" << "3 years \t" << "5 years \t" << endl;
	for (int i = 0; i<count; i++)
	{
		cout << b[i].name << '\t';
		for (int j = 0; j < 5; j++)
			cout << b[i].date[j] << '\t' << '\t';
		cout << endl;
	}
}

int main()
{
	bank<float> B;
	int n, i, j;
	cout << "�������и�����";
	cin >> n;
	B.input(n);
	B.output(n);
	cout << "����������ţ� ";
	cin >> i;
	B.insert(i, n);
	B.output(n);
	cout << "����ɾ������ţ�";
	cin >> j;
	B.deletel(j, n);
	B.output(n);
	system("pause");
	return 0;
}
/*
�������и�����3
�������֣���ҵ
�������ʣ�0.1 0.2 0.3 0.4 0.5
�������֣�ũҵ
�������ʣ�0.2 0.4 0.5 0.6 0.7
�������֣�����
�������ʣ�0.23 0.4 0.5 0.7 0.8
name    3 months        6 months        1 year          3 years         5 years

��ҵ    0.1             0.2             0.3             0.4             0.5

ũҵ    0.2             0.4             0.5             0.6             0.7

����    0.23            0.4             0.5             0.7             0.8

����������ţ� 1
�����������֣��й�
�������ʣ�0.23 0.3 0.4 0.5 0.7
name    3 months        6 months        1 year          3 years         5 years

��ҵ    0.1             0.2             0.3             0.4             0.5

�й�    0.23            0.3             0.4             0.5             0.7

ũҵ    0.2             0.4             0.5             0.6             0.7

����    0.23            0.4             0.5             0.7             0.8

����ɾ������ţ�3
name    3 months        6 months        1 year          3 years         5 years

��ҵ    0.1             0.2             0.3             0.4             0.5

�й�    0.23            0.3             0.4             0.5             0.7

ũҵ    0.2             0.4             0.5             0.6             0.7

*/
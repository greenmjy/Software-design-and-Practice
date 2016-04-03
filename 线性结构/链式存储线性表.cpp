#include <iostream>

using namespace std;
template<class T>
struct node{
	T ele;
	node *next;
};

template<class T>
class reacl{
public:
	reacl();                  //��������
	~reacl();                 //���캯��
	int getLength();           //�õ����Ա�ı�
	T getEle(int);             //�õ�ĳ��λ�õĽڵ�ֵ
	void getList(T);            //�õ����ڵ�λ��
	void insertl(T, int);      //����
	void deletel(int);        //ɾ��
	void displayl();          //��ӡ���
private:
	node<T> *L;
	int length;
};

template<class T>
reacl<T>::reacl()
{
	L = new node<T>;
	length = 0;
	L->next = NULL;
}

template<class T>
reacl<T>::~reacl()
{
	delete L;
}

template<class T>
int reacl<T>::getLength()
{
	return length;
}

template<class T>
T reacl<T>::getEle(int x)
{
	node<T> *p = L;
	for (int i = 0; i < x && (p->next != NULL); i++)
		p = p->next;
	return p->ele;
}

template<class T>
void reacl<T>::getList(T t)
{
	node<T> *p = L;
	int i = 0, temp = 0;
	while (p->next != NULL)
	{
		if (p->ele == t)
		{
			temp = 1;
			cout << "λ�ã�" << i << endl;
			break;
		}
		i++;
		p = p->next;
	}
	if (temp == 0) cout << "û��" << endl;
}
template<class T>
void reacl<T>::insertl(T t, int x)
{
	node<T> *datal = new node<T>;
	node<T> *p = L;
	datal->next = NULL;
	datal->ele = t;
	for (int i = 0; i<x && (p->next != NULL); i++)
		p = p->next;
	datal->next = p->next;
	p->next = datal;
	length++;
}

template<class T>
void reacl<T>::deletel(int x)
{
	node<T> *temp = new node<T>;
	node<T> *p = L;
	for (int i = 0; i<x - 1; i++)
		p = p->next;
	temp = p->next;
	p->next = temp->next;
	length--;
}

template<class T>
void reacl<T>::displayl()
{
	node<T> *p = L;
	while (p->next != NULL)
	{
		p = p->next;
		cout << p->ele << " ";
	}
}
int main()
{
	reacl<int> newl;
	for (int i = 0; i < 30; i++)      //��ʼ���Ա�
	{
		newl.insertl(i, i);
	}
	cout << "���Ա���" << newl.getLength() << endl;
	newl.displayl();
	cout << "�õ�ֵ�ǣ�" << newl.getEle(10) << endl;;
	newl.getList(25);
	newl.insertl(100, 20);         //����
	newl.displayl();
	cout << "���Ա���" << newl.getLength() << endl;
	newl.deletel(21);               //ɾ��
	newl.displayl();
	cout << "���Ա���" << newl.getLength() << endl;
	system("pause");
	return 0;
}
/*
���Ա���30
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
�õ�ֵ�ǣ�9
λ�ã�26
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 100 20 21 22 23 24 25 26 27 28
29 ���Ա���31
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
���Ա���30
�밴���������. . .
*/
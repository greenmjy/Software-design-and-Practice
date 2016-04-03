#include <iostream>

using namespace std;
template<class T>
struct node{
	T ele;
	node *next;
};
template<class T>
class Mystack{
public:
	Mystack();                //���캯��
	~Mystack();               //��������
	void MakeNull();          //ջ�ÿ�
	bool IsEmpty();           //ջ�п�
	void Pop();               //ɾ��ջ��Ԫ��
	void Push(T);              //ѹջ
	T GetTop();              //�õ�ջ��Ԫ��
	void Display();           //��ӡջ
private:
	node<T> *s;
};

template<class T>
Mystack<T>::Mystack()
{
	s = new node<T>;
}

template<class T>
Mystack<T>::~Mystack()
{
	delete s;
}

template<class T>
void Mystack<T>::MakeNull()
{
	s->next = NULL;
}
template<class T>
bool Mystack<T>::IsEmpty()
{
	if (s->next)
		return false;
	else
		return true;
}

template<class T>
void Mystack<T>::Pop()
{
	node<T> *p = new node<T>;
	if (s->next != NULL)
	{
		p = s->next;
		s->next = p->next;
		delete p;
	}
}

template<class T>
void Mystack<T>::Push(T t)
{
	node<T> *p = new node<T>;
	p->ele = t;
	p->next = s->next;
	s->next = p;
	//cout << "tѹջ��" << p->ele << endl;
}

template<class T>
T Mystack<T>::GetTop()
{
	if (IsEmpty())
	{
		cout << "ջ��" << endl;
		return NULL;
	}
	else{
		node<T> *p = new node<T>;
		p=s->next;
		return p->ele;
	}
}

template<class T>
void Mystack<T>::Display()
{
	node<T> *p = new node<T>;
	p = s;
	while (p&&p->next)
	{
		p = p->next;
		cout << p->ele << " ";

	}
	cout << endl;
}
int main()
{
	Mystack<int> mystack;
	int i;
	mystack.MakeNull();
	for (int i = 0; i<10; i++)
		mystack.Push(i);
	mystack.Display();

	cout << "ѹջi��";
	cin >> i;
	mystack.Push(i);
	mystack.Display();
	cout << "ɾ��ջ��Ԫ��\n";
	mystack.Pop();
	mystack.Display();
	cout << "��ʱջ��Ԫ�أ�" << mystack.GetTop() << endl;
	system("pause");
	return 0;
}
/*
9 8 7 6 5 4 3 2 1 0
ѹջi��34
34 9 8 7 6 5 4 3 2 1 0
ɾ��ջ��Ԫ��
9 8 7 6 5 4 3 2 1 0
��ʱջ��Ԫ�أ�9
�밴���������. . .
*/
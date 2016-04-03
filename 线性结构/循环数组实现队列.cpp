#include <iostream>

#define Max 30

using namespace std;

template<class T>
struct myq{
	int head, rear;
	T *ele;
};

template<class T>
class MyQueue{
public:
	MyQueue();
	~MyQueue();
	void MakeNull();            //�������ÿ�
	bool IsEmpty();             //�ж��Ƿ�Ϊ��
	bool IsFull();              //�ж��Ƿ���
	void EnQueue(T);            //���
	T DeQueue();                //����
	int lengthq();               //���еĳ���
private:
	myq<T> *q;
};

template<class T>
MyQueue<T>::MyQueue()
{
	q = new myq<T>;
	q->ele = new T[Max];
}

template<class T>
MyQueue<T>::~MyQueue()
{
	delete q;
	delete[]q->ele;
}

template<class T>
void MyQueue<T>::MakeNull()
{
	q->head = q->rear = 0;
}

template<class T>
bool MyQueue<T>::IsEmpty()
{
	if (q->rear == q->head)
		return true;
	else
		return false;
}

template<class T>
bool MyQueue<T>::IsFull()
{
	if ((q->rear + 1) % Max == q->head)
		return true;
	else
		return false;
}

template<class T>
void MyQueue<T>::EnQueue(T t)
{
	if (IsFull())
		cout << "����";
	else{
		q->rear = (q->rear + 1) % Max;
		q->ele[q->rear] = t;
		//cout<<t<<"���"<<endl;
	}
}

template<class T>
T MyQueue<T>::DeQueue()
{
	if (IsEmpty())
	{
		cout << "�ӿգ�" << endl;
		return NULL;
	}
	else {
		q->head = (q->head + 1) % Max;
		// cout<<q->head<<"head"<<endl;
		//cout<<q->ele[q->head]<<"����"<<endl;
		return q->ele[q->head];
	}
}

template<class T>
int MyQueue<T>::lengthq()
{
	return  (q->rear - q->head + Max) % Max;
}
int main()
{
	MyQueue<int> myqueue;
	myqueue.MakeNull();
	cout << "20������ӣ�" << endl;
	for (int i = 0; i<20; i++)
		myqueue.EnQueue(i);
	cout << "��ǰ���г��ȣ�" << myqueue.lengthq() << endl;
	cout << "���г��ӣ����" << endl;
	for (int i = 0; i<20; i++)
		cout << myqueue.DeQueue() << " ";
	cout << endl;
	system("pause");
	return 0;
}
/*
20������ӣ�
��ǰ���г��ȣ�20
���г��ӣ����
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
�밴���������. . .

*/
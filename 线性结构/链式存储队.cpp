#include <iostream>

using namespace std;

template<class T>
struct node{
	T data;
	node *next;
};

template<class T>
class MyQueue{
public:
	MyQueue();
	~MyQueue();
	void  MakeNull();          //�óɿն�
	bool IsEmpty();            //�жϿն�
	int QueueLength();          //���ض��еĳ���
	void EnQueue(T);              //���
	void DeQueue();               //����
	void Displayq();               //�����
private:
	node<T> *head, *rear;
	int length;
};

template<class T>
MyQueue<T>::MyQueue()
{
	head = new node<T>;
	rear = new node<T>;
	length = 0;
}

template<class T>
MyQueue<T>::~MyQueue()
{
	delete head;
	delete rear;
}

template<class T>
void MyQueue<T>::MakeNull()
{
	head->next = NULL;
	head = rear;              //��ͷ�ǵ�һ���ڵ㣬Ҳ�ǵڶ����ڵ�
}

template<class T>
bool MyQueue<T>::IsEmpty()
{
	if (head == rear)
		return true;
	else return false;
}

template<class T>
int MyQueue<T>::QueueLength()
{
	return length;
}

template<class T>
void MyQueue<T>::EnQueue(T t)
{
	rear->next = new node<T>;
	rear = rear->next;
	rear->data = t;
	rear->next = NULL;
	length++;
}

template<class T>
void MyQueue<T>::DeQueue()
{
	node<T> *temp = new node<T>;
	if (IsEmpty())      cout << "Queue is empty !" << endl;
	else {
		temp = head->next;
		head->next = temp->next;
		delete temp;
		length--;
		if (head->next == NULL)
			rear = head;
	}
}

template<class T>
void MyQueue<T>::Displayq()
{
	node<T> *p = head;
	while (p&&p->next)
	{
		p = p->next;
		cout << p->data << " ";

	}
	cout << endl;
}
int main()
{
	MyQueue<int> myqueue;
	myqueue.MakeNull();
	int i;
	for (int i = 0; i<30; i++)
		myqueue.EnQueue(i);
	myqueue.Displayq();
	cout << "��ǰ���еĳ��ȣ�" << myqueue.QueueLength() << endl;
	cout << "i��ӣ�";
	cin >> i;
	myqueue.EnQueue(i);
	myqueue.Displayq();
	cout << "��ǰ���еĳ��ȣ�" << myqueue.QueueLength() << endl;
	cout << "����:";
	myqueue.DeQueue();
	myqueue.Displayq();
	cout << "��ǰ���еĳ��ȣ�" << myqueue.QueueLength() << endl;
	system("pause");
	return 0;
}
/*
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29

��ǰ���еĳ��ȣ�30
i��ӣ�23
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
23
��ǰ���еĳ��ȣ�31
����:1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28
29 23
��ǰ���еĳ��ȣ�30
�밴���������. . .
*/
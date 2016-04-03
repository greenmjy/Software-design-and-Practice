#ifndef MYQUEUE_H_INCLUDED
#define MYQUEUE_H_INCLUDED
using namespace std;

template<class T>
struct qnode{
T data;
qnode *next;
};

template<class Tq>
class MyQueue{
public:
    MyQueue();
    ~MyQueue();
    void  MakeNull();          //�óɿն�
    bool IsEmpty();            //�жϿն�
    int QueueLength();          //���ض��еĳ���
    Tq Front();                 //���ض���Ԫ��
    void EnQueue(Tq);              //���
    Tq DeQueue();               //����
    void Displayq();               //�����
private:
    qnode<Tq> *head,*rear;
    int length;
};



#endif // MYQUEUE_H_INCLUDED

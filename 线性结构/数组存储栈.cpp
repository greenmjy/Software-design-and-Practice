#include <iostream>
#define Max 100

using namespace std;

template<class T>
struct Stack{
 int top;
 T  *ele;
};
template<class T>
class Mystack{
public:
    Mystack();
    ~Mystack();
    void MakeNull();
    bool IsEmpty();
    T GetTopEle();
    void Pop();
    void Push(T);
    void DisplayStack();
private:
    Stack<T> *s;
};

template<class T>
Mystack<T>::Mystack()         //���캯��
{
    s = new Stack<T>;
    s->ele = new T[Max];
}
template<class T>
Mystack<T>::~Mystack()             //��������
{
    delete s;
    delete []s->ele;
}

template<class T>
void Mystack<T>::MakeNull()           //ջ�ÿ�
{
    s->top = Max;
}

template<class T>
bool Mystack<T>::IsEmpty()            //�п�
{
    if(s->top > Max-1)
         return true;
    else
        return false;
}

template<class T>                        //���ص�ǰջ��Ԫ��
T Mystack<T>::GetTopEle()
{
    if(IsEmpty())
        return NULL;
    else
        return s->ele[s->top];
}

template<class T>
void Mystack<T>::Pop()                 //ɾ��ջ��Ԫ��
{
    if(IsEmpty())
        cout<<"Empty !"<<endl;
    else s->top=s->top+1;
}

template<class T>
void Mystack<T>::Push(T x)              //��ջ
{
    if(s->top==0)
        cout<<"Full !"<<endl;
    else{
        s->top--;
        s->ele[s->top]=x;
    }
}
template<class T>
void Mystack<T>::DisplayStack()        //��ӡջ
{
    cout<<"���ջ��";
    int i=s->top;
   while(s->ele!=NULL&&i<Max)
   {
       cout<<s->ele[i]<<" ";
       i++;
   }
   cout<<endl;
}

int main()
{
    Mystack<int> news;
    int i;
    news.MakeNull();
    for(int i=0;i<30;i++)
        news.Push(i);
    news.DisplayStack();

    cout<<"��ջ:";
    cin>>i;
    news.Push(i);
    news.DisplayStack();

    cout<<"ջ��Ԫ�س�ջ"<<endl;;
    news.Pop();
    news.DisplayStack();
	system("pause");
    return 0;
}
/*
���ջ��29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4
3 2 1 0
��ջ:34
���ջ��34 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5
4 3 2 1 0
ջ��Ԫ�س�ջ
���ջ��29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4
3 2 1 0
�밴���������. . .
*/
#include <iostream>

#define MAX  100
using namespace std;
template<class T>
struct node{
	T *ele;
	int lengthl, sizel;
};

template<class T>
class arrayl
{
public:
	arrayl();               //���캯��
	~arrayl();              //��������
	bool isNull();          //�ж��Ƿ�Ϊ��
	bool isFull();          //�ж��Ƿ���
	int getLength();        //���ص�ǰ���Ա��ʵ�ʳ���
	void getEle(int);       //ĳ��λ�õĽڵ�ֵ
	void getL(T);            //��ֵ�����Ա��е�һ��λ��
	void insertl(T, int);   //���뵽ĳ��λ��
	void deletel(int);      //ɾ��ĳ��λ��
	void displayl();        //��ӡ
private:
	node<T> *p;
};

template<class T>
arrayl<T>::arrayl()
{
	p = new node<T>;
	p->sizel = MAX;
	p->ele = new T[p->sizel];
	p->lengthl = 0;
}

template<class T>
arrayl<T>::~arrayl(){
	delete[]p->ele;
}

template<class T>
bool arrayl<T>::isNull()
{
	if (p->lengthl>0)
		return false;
	else return true;
}

template<class T>
bool arrayl<T>::isFull()
{
	if (p->lengthl == p->sizel)
		return true;
	else return false;
}

template<class T>
int arrayl<T>::getLength()
{
	return p->lengthl;
}

template<class T>
void arrayl<T>::getEle(int x)
{
    if(x>p->lengthl||x<0)
        cout<<"Error !"<<endl;
    else {
        cout<<"ֵΪ��"<<p->ele[x]<<endl;
    }
}

template<class T>
void arrayl<T>::getL(T t)
{
    int temp=0;
    for(int i=0;i<p->lengthl;i++)
    {
        if(t==p->ele[i])
        {
            temp=1;
            cout<<"λ��Ϊ��"<<i<<endl;
            break;
        }
    }
    if(temp==0) cout<<"û��"<<endl;
}
template<class T>
void arrayl<T>::insertl(T t, int x)     //���뵽����x��
{
	if (isFull()) cout << "Full !" << endl;
	else {
		if (x>p->lengthl) cout << "Error !" << endl;
		else{
			p->ele[x] = t;
			for (int i = p->lengthl - 1; i > x; i--)
				p->ele[i + 1] = p->ele[i];
			p->lengthl++;
		}
	}
}
template<class T>
void arrayl<T>::deletel(int x)       //ɾ����x���ڵ�
{
	if (x>p->lengthl || x<0) cout << "Error !" << endl;
	else {
		for (int j = x - 1; j<p->lengthl; j++)
			p->ele[j] = p->ele[j + 1];
		p->lengthl--;
	}
}

template<class T>
void arrayl<T>::displayl()
{
	if (isNull()) cout << "Null !" << endl;
	else {
		for (int j = 0; j<p->lengthl; j++)
			cout << p->ele[j] << " ";
		cout << endl;
	}
}
int main()
{
	arrayl<int> newl;
	int t, x;
	for (int i = 0; i<30; i++)     //��ʼ���Ա�
		newl.insertl(i, i);
	cout << "��ǰ���Ա�ĳ��ȣ�" << newl.getLength() << endl;
	newl.displayl();
	cout<<"����Ҫ��ѯ��λ�ã�";
	cin>>x;
	newl.getEle(x);
    cout<<"����Ҫ��ѯ�Ľڵ㣺";
	cin>>t;
	newl.getL(t);
	cout << "����Ҫ�����t,�����λ��x:";
	cin >> t >> x;
	newl.insertl(t, x);
    cout << "��ǰ���Ա�ĳ��ȣ�" << newl.getLength() << endl;
	newl.displayl();
	cout << "����Ҫɾ����λ��x:";
	cin >> x;
	newl.deletel(x);
	cout << "��ǰ���Ա�ĳ��ȣ�" << newl.getLength() << endl;
	newl.displayl();
	system("pause");
	return 0;
}
/*
��ǰ���Ա�ĳ��ȣ�30
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29

����Ҫ��ѯ��λ�ã�4
ֵΪ��4
����Ҫ��ѯ�Ľڵ㣺23
λ��Ϊ��23
����Ҫ�����t,�����λ��x:90 3
��ǰ���Ա�ĳ��ȣ�31
0 1 2 90 4 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28
29
����Ҫɾ����λ��x:7
��ǰ���Ա�ĳ��ȣ�30
0 1 2 90 4 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29

�밴���������. . .

*/
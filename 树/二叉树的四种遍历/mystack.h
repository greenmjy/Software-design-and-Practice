#ifndef mystack_
#define mystack_

using namespace std;
template<class Ts>
struct snode{
	Ts ele;
	snode *next;
};
template<class Ts>
class Mystack{
public:
	Mystack();                //���캯��
	~Mystack();               //��������
	void MakeNull();          //ջ�ÿ�
	bool IsEmpty();           //ջ�п�
	void Pop();               //ɾ��ջ��Ԫ��
	void Push(Ts);              //ѹջ
	Ts GetTop();              //�õ�ջ��Ԫ��
	void Display();           //��ӡջ
private:
	snode<Ts> *s;
	int length;
};
#endif

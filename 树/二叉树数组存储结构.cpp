/*����������洢�ṹ*/
#include <iostream>

#define Max 100
using namespace std;

template<class T>
class Mytree
{
public:
    Mytree()
    {
        treeA = new T[Max];
    }
    ~Mytree()
    {
        delete []treeA;
    }
    void CreatTree();       //������������
    bool Isempty();           //�Ƿ�Ϊ��
    T GetParent(T);          //�õ����ĸ���
    T GetLchild(T);          //�õ����������
    T GetRchild(T);          //�õ������Ҷ���

    T GetLbrother(T);         //�õ��������ֵ�
    T GetRbrother(T);         //�õ��������ֵ�
private:
    T *treeA;
    int treeL;
};

template<class T>
void Mytree<T>::CreatTree()
{
    cout<<"���鳤�ȣ�";
    cin>>treeL;
    for(int i=1;i<=treeL;i++)     //��ȫ������
    {
        cin>>treeA[i];
    }
}
template<class T>
bool Mytree<T>::Isempty()
{
    return (!treeA);
}
template<class T>
T Mytree<T>::GetParent(T t)
{
    int flag=0;
    for(int i=1;i<=treeL;i++)
    {
        if(treeA[i]==t)
            {
                flag=1;
                return treeA[i/2];
            }
    }
    if(!flag) return NULL;         //û�и��׽ڵ�
}
template<class T>
T Mytree<T>::GetLchild(T t)
{
    int flag =0;
    for(int i=1;i<=treeL;i++)
    {
        if(treeA[i]==t)
        {
            flag =1;
            return treeA[2*i];
        }
    }
    if(!flag) return NULL;
}

template<class T>
T Mytree<T>::GetRchild(T t)
{

    int flag =0;
    for(int i=1;i<=treeL;i++)
    {
        if(treeA[i]==t)
        {
            flag =1;
            return treeA[2*i+1];
        }
    }
    if(!flag) return NULL;
}

template<class T>
T Mytree<T>::GetLbrother(T t)
{

    int flag =0;
    for(int i=1;i<=treeL;i++)
    {
        if(treeA[i]==t)
        {
            if(i!=1&&i%2==1)
            {
                flag =1;
                 return treeA[i-1];
            }
        }
    }
    if(!flag) return NULL;
}

template<class T>
T Mytree<T>::GetRbrother(T t)
{

    int flag =0;
    for(int i=1;i<=treeL;i++)
    {
        if(treeA[i]==t)
        {
            if(i%2==0)
            {
                flag =1;
                return treeA[i+1];
            }
        }
    }
    if(!flag) return NULL;
}
int main()
{
    Mytree<char> tree;
    char a;
    cout<<"һά����洢������"<<endl;
    tree.CreatTree();
    if(tree.Isempty())
    {
        cout<<"��Ϊ�գ�"<<endl;
            return 0;
    }
    cout<<"�����ѯ�Ľڵ㣨����ѯΪ�յ�ʱ���ʾû�е�ǰҪ��Ľڵ㣩��";
    cin>>a;
    cout<<"���׽ڵ㣺"<<tree.GetParent(a)<<endl;
    cout<<"����ӽڵ㣺"<<tree.GetLchild(a)<<endl;
    cout<<"�Ҷ��ӽڵ㣺"<<tree.GetRchild(a)<<endl;
    cout<<"���ֵܽڵ㣺"<<tree.GetLbrother(a)<<endl;
    cout<<"���ֵܽڵ㣺"<<tree.GetRbrother(a)<<endl;
	system("PAUSE");
    return 0;
}
/*
һά����洢������
���鳤�ȣ�10
a b c d e f g h i j
�����ѯ�Ľڵ㣨����ѯΪ�յ�ʱ���ʾû�е�ǰҪ��Ľڵ㣩��d
���׽ڵ㣺b
����ӽڵ㣺h
�Ҷ��ӽڵ㣺i
���ֵܽڵ㣺

*/
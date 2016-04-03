#include <iostream>

using namespace std;

template<class T>
class MaxHeap
{
public:
    MaxHeap(int MaxHeapSize=100);
    ~MaxHeap(){delete []heap;}
    int Size()const{return counter;}
    T Max(){
        if(counter==0)
            {
                cout<<"�ѿ�"<<endl;
                return NULL;
            }
        else return heap[1];}                //���������Ԫ��
    MaxHeap<T>&Insert(const T&x);             //����һ��Ԫ�ص�����
    MaxHeap<T>&DeleteMax(T&x);                //ɾ��������һ��Ԫ��
    void Initialize(T a[],int size,int ArraySize); //��ʼ������
    void Output();                       //������ѣ�������ʽ
private:
    int MaxSize,counter;             //���ѵ�ǰ��С�����ֵ
    T *heap;
};

template<class T>
MaxHeap<T>::MaxHeap(int MaxHeapSize)
{
    MaxSize = MaxHeapSize;
    heap = new T[MaxSize+1];
    counter = 0;
}

template<class T>
MaxHeap<T>&MaxHeap<T>::Insert(const T&x)
{
    if(counter == MaxSize)
        {
            cout<<"����"<<endl;

        }
    int i;
    i=++counter;
    //cout<<"i="<<i<<endl;
    //i++;
    heap[counter]=0;
    //cout<<"i="<<i<<endl;
    while(i!=1&&x>heap[i/2])
    {
        heap[i]=heap[i/2];
        i/=2;
        //cout<<"�Ѵ�С��"<<counter<<endl;
    }
    heap[i] = x;
    //cout<<"�Ѵ�С��"<<counter<<endl;
    //cout<<"���������һ������"<<heap[counter]<<"----"<<heap[6]<<endl;
    return *this;
}

template<class T>
MaxHeap<T>&MaxHeap<T>::DeleteMax(T&x)
{
    if(counter==0)
        cout<<"�ѿ�"<<endl;
    x = heap[1];
    T y = heap[counter--];
    int i=1;
    int ci = 2;
    while(ci<=counter)
    {
        if(ci<counter&&heap[ci]<heap[ci+1]) ci++;
        if(y>=heap[ci]) break;
        heap[i]=heap[ci];
        i = ci;
        ci*=2;
     }
     heap[i]=y;
    return *this;
}

template<class T>
void MaxHeap<T>::Initialize(T a[],int size,int ArraySize)
{
    delete []heap;
    heap = a;
    counter = size;
    MaxSize = ArraySize;
    for(int i = counter/2;i>=1;i--)
    {
        T y=heap[i];

        int c = 2*i;
        while(c<=counter)
        {
            if(c<counter&&heap[c]<heap[c+1])
            {
                c++;
            }
            if(y>=heap[c]) break;
            heap[c/2] =heap[c];
            c*=2;
        }
        heap[c/2] = y;
    }
}

template<class T>
void MaxHeap<T>::Output()
{//д�������ѣ����Ƕ�����ֻ�Ǹ��ݸ��ڵ�����Ҷ��Ӷ���
	cout << "����������ʽ��" << endl;
	for (int i = 1; i <= counter; i++)
		cout << heap[i] << " ";
	cout << endl;
	cout << "��������" << endl;
	T *arr = new T[counter+1];
	for (int i = 1; i <= counter; i++)
		arr[i] = heap[i];
	for (int i = 1; i <= counter; i++)
	{
		for (int j = counter; j > i; j--)
		{
			if (arr[j] > arr[j - 1])
			{
				T temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
	for (int k = 1; k <= counter; k++)
		cout << arr[k] << " ";
	cout << endl;
}
int main()
{
    MaxHeap<int> heap;
    int n=5;
    cout<<"��ʼ�����С��"<<n<<endl;;
    //cin>>n;
    cout<<"��������飺";
    //a = new int[n];
    int a[6]={0,5,4,11,3,7};
    for(int i=1;i<=n;i++)
        //cin>>a[i];
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"��ʼ��Ϊ���ѣ�"<<endl;
    heap.Initialize(a,n,100);
    heap.Output();
    cout<<"\n����10֮������ѣ�\n";
    heap.Insert(10);
    heap.Output();
    cout<<"��ǰ�ѵĴ�С��"<<heap.Size()<<endl;
    cout<<"\nɾ�������֮������ѣ�\n";
    int b=0;
    heap.DeleteMax(b);
    heap.Output();
    cout<<"��ǰ�ѵĴ�С��"<<heap.Size()<<endl;
	getchar();
    return 0;
}
/*
��ʼ�����С��5
��������飺5 4 11 3 7
��ʼ��Ϊ���ѣ�
����������ʽ��
11 7 5 3 4
��������
11 7 5 4 3

����10֮������ѣ�
����������ʽ��
11 7 10 3 4 5
��������
11 10 7 5 4 3
��ǰ�ѵĴ�С��6

ɾ�������֮������ѣ�
����������ʽ��
10 7 5 3 4
��������
10 7 5 4 3
��ǰ�ѵĴ�С��5


*/
/*��ɢ�б�*/
#include<iostream>

#define B 10       //����

using namespace std;

template<class T>
struct node  //ɢ��Ԫ��
{
	T ht;         //Ԫ��ֵ��
	int keys;       //Ԫ��keys�򣬿���ȡ%
};

template<class T>   //T��Ԫ�ص�������K�����ݵ�key��
class MyHash
{
public:
	MyHash();
	~MyHash();
	void insert(T,int);      //����
	void search(int);      //���ҹؼ�ֵΪk��Ԫ��
	void Delete(T);      //ɾ��
	void Output();       //���ɢ�б�
private:
	node<T> hash[B];               //ɢ�б�
	bool empty[B];
};

template<class T>
MyHash<T>::MyHash()
{
	for (int i = 0; i < B; i++)  //��ʼ��Ϊ��
		empty[i] = true;
}

template<class T>
MyHash<T>::~MyHash()
{
	delete[]hash;
	delete[]empty;
}

template<class T>
void MyHash<T>::insert(T t,int k)
{
	int locat = k%B;     //��Bȡģ
	while (locat < B)
	{
		if (empty[locat])
		{
			hash[locat].ht = t;
			hash[locat].keys = k%B;
			empty[locat] = false;
			return;
		}
	 locat++;
	}
	if (locat >= B) cout << "ɢ�б�����(�����)��" << endl;
}

template<class T>
void MyHash<T>::search(int k)
{
	int flag = 0;
	for (int i = 0; i < B; i++)
	{
		if (!empty[i])
		{
			if (hash[i].keys == k)
			{
				flag = 1;
				cout << hash[i].ht << " ";
			}
		}
	}
	if (flag == 0) cout << "û�У�";
	cout << endl;
}

template<class T>
void MyHash<T>::Delete(T t)
{
	int flag = 0;
	for (int i = 0; i < B; i++)
	{
		if (!empty[i])
		{
			if (hash[i].ht == t)
			{
				flag = 1;
				hash[i].ht = NULL;
				hash[i].keys = NULL;
				empty[i] = true;   //ɾ���Ϳ���ֱ�ӽ��˴��ÿ�
			}
		}
	}
}

template<class T>
void MyHash<T>::Output()
{
	cout << "ɢ�б�Ϊ��" << endl;
	for (int i = 0; i < B; i++)
		cout << i<<"\t";
	cout << endl;
	for (int i = 0; i < B; i++)
	{
		if (!empty[i])
			cout << hash[i].ht << '\t';  //���Ԫ��ֵ
		else cout << " " << '\t';
	}
	cout << endl;
}

int main()                                      //��ɢ�б���vs��Ҳ�����ڿ��ж��Գ�ͻ��й¶�ڴ棬��û��������ǿ��Եõ���ȷ�Ľ��
{                                               //ɢ�к�������򵥵ĳ���
	MyHash<int> myhash;
	int n;
	int e, k;
	cout << "����Ҫ�����ɢ�б�Ԫ�ظ�����С��B=10)��" << endl;
	cin >> n;
	cout << "��������Ԫ�ؼ��ؼ�ֵ��"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin >> e >> k;
		myhash.insert(e, k);
	}
	myhash.Output();
	cout << "����Ҫ���ҵ�Ԫ�صĹؼ�ֵ" << endl;
	int num;
	cin >> num;
	myhash.search(num);
	cout << "����Ҫɾ����Ԫ�أ�" << endl;
	int t;
	cin >> t;
	myhash.Delete(t);
	myhash.Output();
	getchar();
	return 0;
}

/*
����Ҫ�����ɢ�б�Ԫ�ظ�����С��B=10)��
6
��������Ԫ�ؼ��ؼ�ֵ��
1 23
2 45
3 65
4 3
5 7
6
9
ɢ�б�Ϊ��
0       1       2       3       4       5       6       7       8       9

1       4       2       3       5               6

����Ҫ���ҵ�Ԫ�صĹؼ�ֵ
3
1 4
����Ҫɾ����Ԫ�أ�
4
ɢ�б�Ϊ��
0       1       2       3       4       5       6       7       8       9

1               2       3       5               6
*/
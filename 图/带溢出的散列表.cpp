#include<iostream>

#define B 10

using namespace std;

template<class T>
struct celltype
{
	T data;
	celltype *next;
};

template<class T>
class HashTable
{
public:
	HashTable();
	int h(T);
	void Insert(T);
	celltype<T>* Search(T k);
	void Delete(T k);
private:
	celltype<T> *hash[B];
};

template<class T>
int HashTable<T>::h(T k)
{
	return k%B;        
}
template<class T>
HashTable<T>::HashTable()
{
	for (int i = 0; i < B; i++)
	{
		hash[i] = NULL;
	}
}
template <class T>
void HashTable<T>::Insert(T k)
{
	int first = h(k);  //ɢ�е�ַ
	if (Search(k) == NULL)   //֮ǰ����ɢ�б���
	{
		if (hash[first] != NULL)
		{
			celltype<T> *p = new celltype<T>;
			celltype<T> *temp = new celltype<T>;
			temp->data = k;
			temp->next = NULL;

			p = hash[first];
			while (p->next!=NULL)
			{
				p = p->next;
			}
			p->next = temp;
		}
		else
		{
			celltype<T> *p = new celltype<T>;
			p->data = k;
			p->next = NULL;
			hash[first] = p;
		}
	}
}

template<class T>
celltype<T>* HashTable<T>::Search(T k)
{
	int locat = h(k);    //�ҵ�k��ɢ�е�ַ
	celltype<T> *bptr;
	bptr = hash[locat];
	while( bptr != NULL)
	{
		if (bptr->data == k)
			return bptr;
		else 
			bptr = bptr->next;

	}
	return bptr;
}

template<class T>
void HashTable<T>::Delete(T k)
{
	int locat = h(k);
	if (Search(k)!=NULL)  //k����
	{
		celltype<T> *p = hash[locat];
		while (p!= NULL)
		{
			if (p->data == k)
			{
				if (p->next != NULL)
					p->data = p->next->data;
				p = p->next;
			}
			else  p=p->next;
			
		}
		if (Search(k)!=NULL) cout << "ɾ��ʧ�ܣ�" << endl;
		else cout << "ɾ���ɹ���" << endl;
		return;
	}
	cout << "û��k" << endl;
}

int main()
{
	HashTable<int> hashtable;
	int a = 1;
	cout << "��������ɢ�б�" << endl;
	cout << "����ɢ�б�:" << endl;
	while (a != -1)
	{
		cin >> a;
		if(a!=-1) hashtable.Insert(a);
	}
	cout << "������ҵ�ֵ��";
	cin >> a;
	if (hashtable.Search(a)) cout<<"����ָ�룺" << hashtable.Search(a) << endl;
	else cout << "û���ҵ���" << endl;
	cout << "����ɾ����ֵ��";
	cin >> a;
	hashtable.Delete(a);
	getchar();
	return 0;
}
/*
��������ɢ�б�
����ɢ�б�:
12 2 32 4 31 -1
������ҵ�ֵ��2
����ָ�룺011192B8
����ɾ����ֵ��2
ɾ���ɹ���


*/


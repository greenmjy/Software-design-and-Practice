#include <iostream>
#include <string>
using namespace std;

#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10

int OK = 1;
int OVER = 0;
int ERROR = 0;

typedef struct
{ 
	char num[10];   //���
	char name[20];  //����
	char sex[6];    //�Ա�
	char phone[13]; //�绰
	char addr[31];  //��ַ
} DataType;

typedef struct
{
	DataType *elem;
	int length;   //��ǰ����
	int listsize; //���Ա�ĳ���
}SqList;

/*���˵�*/
int menu_select()
{
	int choice;
	cout << "\t\t����ͨѶ¼����ϵͳ\t\t\n";
	cout << "***************************************************\n";
	cout << "* 1.����  " << "2.����  " << "3.��ѯ  " << "4.ɾ��  " << "5.���  " << "0.�˳� *\n";
	cout << "***************************************************\n";
	cout << "��ѡ����� 0-5�� ";
	for (;;)
	{
		cin >> choice;
		if (choice<0 || choice>5)//С��0����5
			cout << "���������ѡ0-5:";
		else
			break;
	}
	cout << endl;
	return choice;
}

void InitList(SqList &L)            //��ʼ�����Ա�
{
	L.elem = (DataType *)malloc(LIST_INIT_SIZE*sizeof(DataType));

	if (!L.elem)
		exit(OVER);

	L.length = 0;
	L.listsize = LIST_INIT_SIZE;        
}

void CreateList(SqList &L) //����ͨѶ¼
{
	L.elem = (DataType *)malloc(LIST_INIT_SIZE*sizeof(DataType));

	if (!L.elem)
		exit(OVER);

	L.length = 0;
	L.listsize = LIST_INIT_SIZE;//��Ϊ����һ��ͨѶ¼�������¿�ʼ����һ��������Ҫ��ʼ��

	int i = 0;
	int flag = 1;

	while (flag == 1)
	{
		cout << "���(4)-����(8)-�Ա�(3)-�绰(11)-��ַ(31)\n";

		cin >> L.elem[i].num >> L.elem[i].name >> L.elem[i].sex >> L.elem[i].phone >> L.elem[i].addr;
		i++;
		L.length++;

		cout << "�Ƿ�Ҫ������ӣ�(0 or 1)��";
		cin >> flag;
		cout << endl;
	}
}

int InsertNode(SqList &L, int i, DataType x)
{
	if (i<1 || i>L.length + 1)//����L.length��1��Ŀ���ǣ��û����ܻ������߽���Ԫ�أ������壬
		return ERROR;

	DataType * newbase;
	DataType * p, *q;
	if (L.length >= L.listsize)
	{
		newbase = (DataType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(DataType));
		if (!newbase)
			exit(OVER);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}

	/*�������*/
	q = &(L.elem[i - 1]);//qΪ��i��Ԫ�ص�λ��
	for (p = &(L.elem[L.length - 1]); p >= q; p--)
	{
		strcpy_s((p + 1)->num, p->num);
		strcpy_s((p + 1)->name, p->name);
		strcpy_s((p + 1)->sex, p->sex);
		strcpy_s((p + 1)->phone, p->phone);
		strcpy_s((p + 1)->addr, p->addr);//i-1֮���Ԫ�����κ���һλ
	}
	strcpy_s(q->num, x.num);
	strcpy_s(q->name, x.name);
	strcpy_s(q->sex, x.sex);
	strcpy_s(q->phone, x.phone);
	strcpy_s(q->addr, x.addr);

	L.length++;
	return OK;
}
//------ͨѶ¼��ѯ------------

void computeLPSArray(char *pat, int M, int *lps);

int KMPSearch(char *pat, char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	int *lps = (int *)malloc(sizeof(int)*M);
	int j = 0;  // index for pat[]

	computeLPSArray(pat, M, lps);

	int i = 0;  // index for txt[]
	while (i < N)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}
		if (j == M)
		{
			j = lps[j - 1];
			return 1;//ƥ�䵽��Ӧ�ַ���
		}

		else if (pat[j] != txt[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	free(lps); 
	return 0;
}

void computeLPSArray(char *pat, int M, int *lps)
{
	int len = 0;  // ��¼ǰһ��[�ƥ���ǰ׺�ͺ�׺]�ĳ���
	int i;

	lps[0] = 0; // lps[0] ������ 0
	i = 1;

	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else // ��� (len == 0)
			{
				lps[i] = 0; //û��һ��ƥ���
				i++;
			}
		}
	}
}


void ListPhoneFind(char a[], SqList &L)   //��̬��ѯ����
{
	int len = 0;
	for (int i = 0;; i++)
	{
		if (a[i] == '\0')
			break;
		else len++;
	}
	DataType *p;
	char *b=new char[len];
	p = L.elem;
	for (int i = 1; i <= L.length; i++)
	{
		for (int j = 0; j < len; j++)
		{
			b[j] = p[i - 1].phone[j];    //�ַ����Ĳ��ָ���
		}
		b[len] = '\0';                  //�����ַ�����β��
		if (strcmp(a, b) == 0)
			cout << p[i - 1].num << " " << p[i - 1].name << " " << p[i - 1].sex << " " << p[i - 1].phone << " " << p[i - 1].addr << " "<<endl;
	}
	cout << "�Ƿ����������루0/1��";
	int nu;
	cin >> nu;
	if (nu)  {
		cout << a;
		char *a1=new char[11-len];
		cin >> a1;
		strcat_s(a,11,a1);    
		ListPhoneFind(a, L);
	}
	else return;
}

int ListFind(SqList &L)
{// ����ͨѶ¼���Ա��ϵĲ���
	int i = 1;
	int xz;
	DataType *p;
	p = L.elem;
	char SNum[5];
	char SName[9];
	char SPnum[11];
	char Saddr[30];

	do
	{
		cout << "1 ����Ų�ѯ  2 ��������ѯ  3���绰��ѯ  4����ַ��ѯ\n";
		cin >> xz;
		cout << endl;
		if (xz != 1 && xz != 2&&xz!=3&& xz!=4)
			cout << "�������\n";
	} while (xz != 1 && xz != 2 && xz!=3&&xz!=4);

	if (xz == 1)
	{
		int j = 0;
		cout << "�����ţ�";
		cin >> SNum;
		cout << endl;
		while (i <= L.length && strcmp(p[i - 1].num, SNum) != 0)
			i++;
		if (i>L.length)
			return 0;
		else
			return i;
	}
	else if (xz==2)
	{
		cout << "����������";
		cin >> SName;
		cout << endl;

		while (i <= L.length && strcmp(p[i - 1].name, SName) != 0)
			i++;

		if (i>L.length)
			return 0;
		else
			return i;
	}

	else if (xz==3)
	{
		cout << "����绰��";
		cin >> SPnum;
		ListPhoneFind(SPnum, L);                      //����绰�Ķ�̬��ѯ
		return -1;
	}
	else
	{
		cout << "�����ַ��";                       //�����ַ��KMPƥ���ѯ
		cin >> Saddr;
		int flag = 0;
		for (int i = 0; i < L.length; i++)
		{
			if (KMPSearch(Saddr, p[i].addr))
			{
				flag = 1;
				cout << p[i].num << " " << p[i].name << " " << p[i].sex << " " << p[i].phone << " " << p[i].addr << endl;
			}
		}
		if(flag) return -1;
		else return 0;
	}

}
/*ɾ����ϵ��*/
int DelNode(SqList &L)
{
	DataType * p;
	DataType * q;
	int i;

	cout << "Ҫɾ���ĸ�λ���ϵ�Ԫ�أ�:";
	cin >> i;
	cout << endl;

	if (i<1 || i>L.length)
		return ERROR;//��������Ĵ���

	p = &(L.elem[i - 1]);
	q = L.elem + L.length - 1;

	for (p; p<q; p++)
	{
		strcpy_s(p->num, (p + 1)->num);//i-1֮���Ԫ�����κ���һλ
		strcpy_s(p->name, (p + 1)->name);
		strcpy_s(p->sex, (p + 1)->sex);
		strcpy_s(p->phone, (p + 1)->phone);
		strcpy_s(p->addr, (p + 1)->addr);
	}//i֮���Ԫ����������
	L.length--;
	return OK;
}

void PrintList(SqList &L)  //���ͨѶ¼
{
	int i;
	for (i = 0; i<L.length; i++)
	{
		cout << L.elem[i].num << " " << L.elem[i].name << " " << L.elem[i].sex << " "
			<< L.elem[i].phone << " " << L.elem[i].addr << endl;
	}
	if (L.length == 0)
		cout << "ͨѶ¼��û��Ԫ�أ�\n";
	cout << endl;
}

//������
void main()
{
	SqList L;
	InitList(L);
	for (;;)
	{
		switch (menu_select())
		{
		case 1:
			cout << "*    ͨ Ѷ ¼ �� �� �� �� �� ��     *"<<endl;
			CreateList(L);
			break;
		case 2:
			cout << "*    ͨ Ѷ �� �� Ϣ �� �� ��     *"<<endl;
			cout << endl;
			cout << "���(4)-����(8)-�Ա�(3)-�绰(11)-��ַ(31)"<<endl;
			DataType p; //�����½��
			cin >> p.num >> p.name >> p.sex >> p.phone >> p.addr;

			int i;
			int m;
			cout << "��嵽�ĸ�λ���ϣ� ";
			cin >> i;
			cout << endl;

			m = InsertNode(L, i, p);

			if (m == ERROR)
				cout << "�������Ԫ��λ�ó����˽��ޣ�"<<endl;
			else
				cout << "�Ѿ������˸�Ԫ�أ�\n"<<endl;
			break;
		case 3:
			int a;
			cout << "*    ͨ Ѷ �� �� Ϣ �� �� ѯ     *\n";
			a = ListFind(L);

			if (a != 0&&a!=-1)
			{
				cout << "���(4)-����(8)-�Ա�(3)-�绰(11)-��ַ(31)"<<endl;
				cout << L.elem[a - 1].num << " " << L.elem[a - 1].name << " " << L.elem[a - 1].sex << " "
					<< L.elem[a - 1].phone << " " << L.elem[a - 1].addr << endl;
				cout << endl;
			}
			else if (a==0)
				cout << "û�в鵽Ҫ��ѯ��ͨѶ�ߣ�\n";
			break;
		case 4:
			int b;
			cout << "*    ͨ Ѷ �� �� Ϣ �� ɾ ��     *\n";
			b = DelNode(L);  //ɾ�����
			if (b == 0)
				cout << "�������Ԫ��λ�ó������ޣ�\n";
			else
				cout << "�Ѿ��ɹ�ɾ���˸�Ԫ�أ�\n";
			break;
		case 5:
			cout << "*    ͨ Ѷ �� �� Ϣ �� �� ��     *\n";
			PrintList(L);
			break;
		case 0:
			cout << "\t  ͨѶ¼�˳�����ӭʹ�ã� \n";
			system("pause");
			return;
		}
	}
}

/*
���н����

����ͨѶ¼����ϵͳ
***************************************************
* 1.����  2.����  3.��ѯ  4.ɾ��  5.���  0.�˳� *
***************************************************
��ѡ����� 0-5�� 1

*    ͨ Ѷ ¼ �� �� �� �� �� ��     *
���(4)-����(8)-�Ա�(3)-�绰(11)-��ַ(31)
1 ���� �� 1130310723 ��������ҵ��ѧ
�Ƿ�Ҫ������ӣ�(0 or 1)��1

���(4)-����(8)-�Ա�(3)-�绰(11)-��ַ(31)
2 ���� �� 11303107244 ������������
�Ƿ�Ҫ������ӣ�(0 or 1)��1

���(4)-����(8)-�Ա�(3)-�绰(11)-��ַ(31)
3 ���� �� 1130934 �������ϸ���
�Ƿ�Ҫ������ӣ�(0 or 1)��0

����ͨѶ¼����ϵͳ
***************************************************
* 1.����  2.����  3.��ѯ  4.ɾ��  5.���  0.�˳� *
***************************************************
��ѡ����� 0-5�� 2

*    ͨ Ѷ �� �� Ϣ �� �� ��     *

���(4)-����(8)-�Ա�(3)-�绰(11)-��ַ(31)
4 ���� Ů 12324 ����ֱ�ֹ�����
��嵽�ĸ�λ���ϣ� 4

�Ѿ������˸�Ԫ�أ�

����ͨѶ¼����ϵͳ
***************************************************
* 1.����  2.����  3.��ѯ  4.ɾ��  5.���  0.�˳� *
***************************************************
��ѡ����� 0-5�� 3

*    ͨ Ѷ �� �� Ϣ �� �� ѯ     *
1 ����Ų�ѯ  2 ��������ѯ  3���绰��ѯ  4����ַ��ѯ
1

�����ţ�1

���(4)-����(8)-�Ա�(3)-�绰(11)-��ַ(31)
1 ���� �� 1130310723 ��������ҵ��ѧ

����ͨѶ¼����ϵͳ
***************************************************
* 1.����  2.����  3.��ѯ  4.ɾ��  5.���  0.�˳� *
***************************************************
��ѡ����� 0-5�� 3

*    ͨ Ѷ �� �� Ϣ �� �� ѯ     *
1 ����Ų�ѯ  2 ��������ѯ  3���绰��ѯ  4����ַ��ѯ
2

��������������

���(4)-����(8)-�Ա�(3)-�绰(11)-��ַ(31)
1 ���� �� 1130310723 ��������ҵ��ѧ

����ͨѶ¼����ϵͳ
***************************************************
* 1.����  2.����  3.��ѯ  4.ɾ��  5.���  0.�˳� *
***************************************************
��ѡ����� 0-5�� 3

*    ͨ Ѷ �� �� Ϣ �� �� ѯ     *
1 ����Ų�ѯ  2 ��������ѯ  3���绰��ѯ  4����ַ��ѯ
3

����绰��113
1 ���� �� 1130310723 ��������ҵ��ѧ
2 ���� �� 11303107244 ������������
3 ���� �� 1130934 �������ϸ���
�Ƿ����������루0/1��1
113031
1 ���� �� 1130310723 ��������ҵ��ѧ
2 ���� �� 11303107244 ������������
�Ƿ����������루0/1��1
1130310724
2 ���� �� 11303107244 ������������
�Ƿ����������루0/1��0
����ͨѶ¼����ϵͳ
***************************************************
* 1.����  2.����  3.��ѯ  4.ɾ��  5.���  0.�˳� *
***************************************************
��ѡ����� 0-5�� 3

*    ͨ Ѷ �� �� Ϣ �� �� ѯ     *
1 ����Ų�ѯ  2 ��������ѯ  3���绰��ѯ  4����ַ��ѯ
4

�����ַ��������
1 ���� �� 1130310723 ��������ҵ��ѧ
2 ���� �� 11303107244 ������������
3 ���� �� 1130934 �������ϸ���
����ͨѶ¼����ϵͳ
***************************************************
* 1.����  2.����  3.��ѯ  4.ɾ��  5.���  0.�˳� *
***************************************************
��ѡ����� 0-5�� 4

*    ͨ Ѷ �� �� Ϣ �� ɾ ��     *
Ҫɾ���ĸ�λ���ϵ�Ԫ�أ�:2

�Ѿ��ɹ�ɾ���˸�Ԫ�أ�
����ͨѶ¼����ϵͳ
***************************************************
* 1.����  2.����  3.��ѯ  4.ɾ��  5.���  0.�˳� *
***************************************************
��ѡ����� 0-5�� 5

*    ͨ Ѷ �� �� Ϣ �� �� ��     *
1 ���� �� 1130310723 ��������ҵ��ѧ
3 ���� �� 1130934 �������ϸ���
4 ���� Ů 12324 ����ֱ�ֹ�����

����ͨѶ¼����ϵͳ
***************************************************
* 1.����  2.����  3.��ѯ  4.ɾ��  5.���  0.�˳� *
***************************************************
��ѡ����� 0-5�� 0

ͨѶ¼�˳�����ӭʹ�ã�
*/
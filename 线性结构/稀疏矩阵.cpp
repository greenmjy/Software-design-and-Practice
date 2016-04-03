#include <iostream>
#define Max 1024

using namespace std;

template<class T>
struct node{
	int row, col;
	T data;
};

template<class T>
class Matrix{
public:
	Matrix();
	~Matrix();
	void input(int, int, int);           //����
	void Transpose(int, int, int);      //ת��
	void output(int, int, int);         //���
private:
	node<T> *p;
	int num;
};

template<class T>
Matrix<T>::Matrix()
{
	p = new node<T>[num];

}

template<class T>
Matrix<T>::~Matrix()
{
	delete[]p;
}

template<class T>
void Matrix<T>::input(int nrow, int ncol, int num)
{
	cout << "����Ԫ���С��С�Ԫ��ֵ��";
	for (int i = 0; i<num; i++)
		cin >> p[i].row >> p[i].col >> p[i].data;
	for (int i = 0; i < num; i++)
		cout << "��" << i + 1 << "��Ԫ�صĵ�" << p[i].row + 1 << "�е�" << p[i].col + 1 << "��Ԫ��ֵ�ǣ�" << p[i].data << "\n";
}
template<class T>
void Matrix<T>::Transpose(int nrow, int ncol, int num)
{
	int temp = ncol;
	ncol = nrow;
	nrow = temp;
	for (int i = 0; i<num; i++)
	{
		int temp1 = p[i].col;
		p[i].col = p[i].row;
		p[i].row = temp1;
	}
}

template<class T>
void Matrix<T>::output(int nrow, int ncol, int num)
{
	for (int i = 0; i<nrow; i++)
	{
		for (int j = 0; j<ncol; j++)
		{
			int temp = 0;
			for (int count = 0; count < num; count++)
			{
				if (p[count].row == i&&p[count].col == j)
				{
					cout << p[count].data << " ";
					temp = 1;
					break;
				}
			}
			if (temp == 0) cout << "0 ";
		}
		cout << endl;
	}
}

int main()
{
	Matrix<int> news;
	int nrow, ncol, num;
	cout << "�����������У��Լ���0Ԫ�صĸ�����";
	cin >> nrow >> ncol >> num;
	news.input(nrow, ncol, num);
	cout << "����" << endl;
	news.output(nrow, ncol, num);
	cout << "ת�þ���" << endl;
	news.Transpose(nrow, ncol, num);
	news.output(ncol, nrow, num);
	system("pause");
	return 0;
}
/*
�����������У��Լ���0Ԫ�صĸ�����5 5 5
����Ԫ���С��С�Ԫ��ֵ��1 1 2
2 3 8
4 3 6
1 4 3
0 3 2
��1��Ԫ�صĵ�2�е�2��Ԫ��ֵ�ǣ�2
��2��Ԫ�صĵ�3�е�4��Ԫ��ֵ�ǣ�8
��3��Ԫ�صĵ�5�е�4��Ԫ��ֵ�ǣ�6
��4��Ԫ�صĵ�2�е�5��Ԫ��ֵ�ǣ�3
��5��Ԫ�صĵ�1�е�4��Ԫ��ֵ�ǣ�2
����
0 0 0 2 0
0 2 0 0 3
0 0 0 8 0
0 0 0 0 0
0 0 0 6 0
ת�þ���
0 0 0 0 0
0 2 0 0 0
0 0 0 0 0
2 0 8 0 6
0 3 0 0 0
*/
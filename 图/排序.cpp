/**< �������򣬿������򣬲�������ϣ������
ѡ�����򣬶����� ���鲢���򣬻�������*/
#include <iostream>
#include<ctime>

#define Max 100000000
using namespace std;

template<class T>
class SortR
{
public:
	SortR()
	{
		arr = new T[Max];
	}
	~SortR(){
		delete[]arr;
	}
	void InputValue();
	void BubbleSort();              //ð������
	void QuickSort();               //��������
	void InsertSort();              //��������
	void HillSort();                //ϣ������
	void SelectSort();              //ѡ������
	void HeapSort();                //������
	void MergeSort();               //�鲢����
	void BaseSort();                //��������
	void Display(T*);               //���������
private:
	void Swap(T*, T*)const;

	int findPivot(int, int, T*)const;
	int Partition(int, int, T, T*)const;
	void QuickSortRev(int, int, T*);     //���ŵݹ�

	void PushDown(int, int,T*)const;      //�����������

	void  Merge_array(T*,int,int,int,T*);        //�ϲ���������
	void merge_sort(T*, int, int, T*);         //�鲢���򣬵ݹ�ʵ��

	T GetDigit(T x, int d);
	void msdradix_sort(T*,int,int,int);

	T *arr;
	int n;
};

template<class T>
void SortR<T>::InputValue()
{
	cout << "���������С��";
	//cin >> n;
	n = 10000;
	cout << "��������Ԫ�أ�";
	srand((T)time(NULL));
	for (int i = 0; i < n; i++)
		//cin >> arr[i];
		arr[i] = rand() %100000;
}

template<class T>
void SortR<T>::Swap(T*t1, T*t2)const   //����
{
	T temp;
	temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

/**< --------ð������------- */
template<class T>
void SortR<T>::BubbleSort()
{
	//---ʱ�����
	clock_t start, finish;
	double totaltime;
	start = clock();
//----------------------------------------------------
	T *bubble_arr = new T[n];
	for (int i = 0; i < n; i++)
		bubble_arr[i] = arr[i];

	for (int i = 0; i<n; i++)
	{
		for (int j = n - 1; j>i; j--)
		{
			if (bubble_arr[j]<bubble_arr[j - 1])         //����ı�ǰһ��С�ͽ���
				Swap(&bubble_arr[j], &bubble_arr[j - 1]);
		}
	}

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "����ʱ�䣺" << totaltime << "��" << endl;

	//Display(bubble_arr);
	//Display(arr);

}
/**< -------��������-------- */
template<class T>
int SortR<T>::findPivot(int i, int j, T*quick_arr)const    
{
	T firstkey;
	int k;
	firstkey = quick_arr[i];
	for (k = i + 1; k <= j; k++)
	{
		if (quick_arr[k]>firstkey) return k;
		else if (quick_arr[k]<firstkey) return i;
		else  return -1;   //û�в�ͬ�ؼ���
	}
	return 0;
}

template<class T>
int SortR<T>::Partition(int i, int j, T piovt, T *quick_arr)const
{
	int l = i, r = j;
	do{
		Swap(&quick_arr[l], &quick_arr[r]);
		while (quick_arr[l]<piovt) l++;
		while (quick_arr[r] >= piovt) r--;
	} while (l <= r);
	return l;
}

template<class T>
void SortR<T>::QuickSortRev(int i, int j, T *quick_arr)
{
	T piovt;
	int piovtindex;
	int k;
	piovtindex = findPivot(i, j, quick_arr);
	if (piovtindex >= 0)
	{
		piovt = quick_arr[piovtindex];
		k = Partition(i, j, piovt, quick_arr);
		//Display(quick_arr);            //���
		return;                      
		QuickSortRev(i, k - 1, quick_arr);
		QuickSortRev(k, j, quick_arr);
	}
}

template<class T>
void SortR<T>::QuickSort()
{
	//---ʱ�����
	clock_t start, finish;
	double totaltime;
	start = clock();

	T *quick_arr = new T[n];
	for (int i = 0; i < n; i++)
		quick_arr[i] = arr[i];

	QuickSortRev(0, n - 1, quick_arr);

	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "����ʱ�䣺" << totaltime << "��" << endl;
	//Display(arr);
}
/*------��������------*/
template<class T>
void SortR<T>::InsertSort()     //��������
{
	//---ʱ�����
	clock_t start, finish;
	double totaltime;
	start = clock();

	T *insert_arr = new T[n];
	for (int i = 0; i < n; i++)
		insert_arr[i+1] = arr[i];
	insert_arr[0] = -1;
	for (int i = 1; i<n; i++)
	{
		int j = i;
		while (insert_arr[j]<insert_arr[j - 1])
		{
			Swap(&insert_arr[j], &insert_arr[j - 1]);
			j--;
		}
	}
	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "����ʱ�䣺" << totaltime << "��" << endl;

	//for (int i = 1; i <= 20; i++)
	//	cout << insert_arr[i] << " ";
	//cout << endl;
	//Display(arr);

}
/*-------ϣ������-----------*/
template<class T>
void SortR<T>::HillSort()
{

	//---ʱ�����
	clock_t start, finish;
	double totaltime;
	start = clock();


	T *hill_arr = new T[n];
	for (int i = 0; i<n; i++)
		hill_arr[i] = arr[i];

	int j, gap;
	for (gap = n / 2; gap > 0;gap/=2)
	for (j = gap; j < n; j++)
	{
		if (hill_arr[j] < hill_arr[j - gap])
		{
			T temp = hill_arr[j];
			int k = j - gap;
			while (k >= 0 && hill_arr[k]>temp)
			{
				hill_arr[k + gap] = hill_arr[k];
				k -= gap;
			}
			hill_arr[k + gap] = temp;
		}
	}
	//Display(hill_arr);

	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "����ʱ�䣺" << totaltime << "��" << endl;

}
/*--------ѡ������--------*/
template<class T>
void SortR<T>::SelectSort()
{

	//---ʱ�����
	clock_t start, finish;
	double totaltime;
	start = clock();

	T *select_arr = new T[n];
	for (int i = 0; i < n; i++)
		select_arr[i] = arr[i];

	T minindex;  //�洢��С��Ԫ��
	for (int i = 0; i<n; i++)
	{
		minindex = select_arr[i];
		for (int j = i + 1; j<n; j++)
		{
			if (select_arr[j]<minindex)
			{
				minindex = select_arr[j];
			}
		}
		Swap(&select_arr[i], &minindex);
	}
	//Display(select_arr);

	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "����ʱ�䣺" << totaltime << "��" << endl;
}
/*--------������---------*/            
template<class T>
void SortR<T>::PushDown(int first, int last,T *heap_arr)const
{

	int r;
	r = first;
	while (r <= last/2)
	if ((r == last / 2) && (last % 2 ==0))         //r��һ�����ӣ���2*r
	{
		if (heap_arr[r] > heap_arr[2 * r])
			Swap(&heap_arr[2*r],&heap_arr[r]);
		r = last;
	}
	else if ((heap_arr[r] > heap_arr[2 * r]) && (heap_arr[2*r] <= heap_arr[2 * r + 1]))
	{                                            //r������ӽ���
		Swap(&heap_arr[2*r], &heap_arr[r]);
		r = 2 * r;
	}
	else if ((heap_arr[r]> heap_arr[2 * r + 1]) && (heap_arr[2 * r+1] <= heap_arr[2*r]))
	{                                             //r���Ҷ��ӽ���
		Swap(&heap_arr[2*r+1], &heap_arr[r]);
		r = r * 2 + 1;
	}
	else  r = last; 
}

template<class T>
void SortR<T>::HeapSort()
{

	//---ʱ�����
	clock_t start, finish;
	double totaltime;
	start = clock();

	T *heap_arr = new T[n];
	for (int i = 0; i < n; i++)
		heap_arr[i + 1] = arr[i];

	int i;
	for (i = n / 2; i >= 1; i--)
		PushDown(i, n, heap_arr);
	for (i = n; i>1; i--)
	{
		Swap(&heap_arr[1], &heap_arr[i]);

		PushDown(1,i-1, heap_arr);
	}

	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "����ʱ�䣺" << totaltime << "��" << endl;

	/*for (int i = n; i> 0; i--)
		cout << heap_arr[i] << " ";
	cout << endl;*/
}
/*----------�鲢����-----------*/
template<class T>
void SortR<T>::Merge_array(T*merge_arr, int first, int midle, int last, T*temp)
{
	int i = first, j = midle + 1;
	int m = midle, l = last, k = 0;
	while (i <= m && j <= l)
	{
		if (merge_arr[i] <= merge_arr[j])
			temp[k++] = merge_arr[i++];
		else
			temp[k++] = merge_arr[j++];
	}
	while (i <= m)
		temp[k++] = merge_arr[i++];
	while (j <= l)
		temp[k++] = merge_arr[j++];
	for (i = 0; i < k; i++)
		merge_arr[first + i] = temp[i];
}

template<class T>
void SortR<T>::merge_sort(T*merge_arr,int first,int last,T*temp)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		merge_sort(merge_arr, first, mid, temp);
		merge_sort(merge_arr, mid + 1, last, temp);
		Merge_array(merge_arr, first, mid, last, temp);
	}
}

template<class T>
void SortR<T>::MergeSort()
{

	//---ʱ�����
	clock_t start, finish;
	double totaltime;
	start = clock();

	T *merge_arr = new T[n];
	for (int i = 0; i < n; i++)
		merge_arr[i + 1] = arr[i];

	T *p = new T[n];
	merge_sort(merge_arr, 1, n, p);


	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "����ʱ�䣺" << totaltime << "��" << endl;

	/*for (int i = 1; i <= n; i++)
		cout << merge_arr[i] << " ";
	cout << endl;*/
}
/*---------��������------------*/
template<class T>
T SortR<T>::GetDigit(T x, int d)
{
	int a[] = { 1, 1, 10};//�ŵ���100���ڵ�
	return (x / a[d]) % 10;
}

template<class T>
void SortR<T>::msdradix_sort(T *base_arr,int first,int last,int d)
{
	int radix = 10;
	int count[10], i, j;
	for (i = 0; i < radix; i++)
		count[i] = 0;
	T*bucker = new T[n];
	for (i = first; i <= last; i++)
		count[GetDigit(base_arr[i], d)]++;

	for (i = 1; i < radix; i++)
		count[i] += count[i - 1];

	for (i = last; i >= first; --i)
	{
		j = GetDigit(base_arr[i], d);
		bucker[count[j] - 1] = base_arr[i];
		--count[j];
	}

	for (i = first,j = 0; i <= last; i++,j++)
		base_arr[i] = bucker[j];

	for (i = 0; i < radix; i++)
	{
		int p1 = first + count[i];
		int p2 = first + count[i + 1] - 1;
		if (p1<p2&&d>1)
			msdradix_sort(base_arr, p1, p2, d - 1);
	}
}

template<class T>
void SortR<T>::BaseSort()
{
	/*cout << "������Ҫ�ŵ�������Ĭ��0-99��,nֵ�����ʼ�ģ���"<<endl;
	T *base_arr = new T[n];
	for (int i = 0; i < n; i++)
		cin >> base_arr[i];*/

	//---ʱ�����
	clock_t start, finish;
	double totaltime;
	start = clock();

	T *base_arr = new T[n];
	for (int i = 0; i < n; i++)
		base_arr[i] = arr[i];

	msdradix_sort(base_arr, 0, n - 1, 2);

	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "����ʱ�䣺" << totaltime << "��" << endl;

	cout << "��������" << endl;
	//Display(base_arr);

}
/*----------�������---------*/
template<class T>
void SortR<T>::Display(T *newarray)
{
	for (int i = 0; i<20; i++)
		cout << newarray[i] << " ";
	cout << endl;

}
/*--------������-----------*/
int main()
{
	cout << "���򷽷�����С���󣩣�" << endl;
	SortR<int> mysort;
	mysort.InputValue();
	cout << "��������" << endl;
	mysort.BubbleSort();
	cout << "��������" << endl;
	mysort.QuickSort();
	cout << "��������" << endl;
	mysort.InsertSort();
	cout << "ϣ������" << endl;                  
	mysort.HillSort();
	cout << "ѡ������" << endl;
	mysort.SelectSort();
	cout << "������" << endl;              
	mysort.HeapSort();
	cout << "�鲢����" << endl;           
	mysort.MergeSort();
	cout << "��������" << endl;           
	mysort.BaseSort();
	system("pause");
	return 0;
}
/*
����100000
���򷽷�����С���󣩣�
���������С����������Ԫ�أ���������
����ʱ�䣺96.723��
��������
����ʱ�䣺0.001��
��������
����ʱ�䣺73.361��
ϣ������
����ʱ�䣺0.027��
ѡ������
����ʱ�䣺13.033��
������
����ʱ�䣺0.065��
�鲢����
����ʱ�䣺0.027��
��������
����ʱ�䣺0.02��
��������
�밴���������. . .


*/
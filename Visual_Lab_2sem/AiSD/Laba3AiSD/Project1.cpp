#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

void sortMethodPuz(int*, int); // ����� �������� n^2 n
void sortMethodInsert(int*, int); // ����� ������� n^2 n
void sortMethodSelection(int*, int); // ����� ������ n^2 n^2
void quickSort(int* arr, int first, int last); // ������� ���������� n log n  n
void outArr(int*, int); // ����� ��������

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size,
		start,
		end,
		timePuz,
		timeShella,
		timeSel,
		timeFast;

	cout << "������� ����� ���������, ������� ����� � �������: "; cin >> size;

	int* A = new int[size],
		* B = new int[size],
		* C = new int[size],
		* D = new int[size],
		* E = new int[size];

	cout << "������ �(��������) ������� ��:\n";
	srand(time(NULL));
	for (int i = 0, num; i < size; i++)
	{
		num = rand() % 100;
		A[i] = B[i] = C[i] = D[i] = E[i] = num;
	}
	outArr(A, size);

	cout << "\n";

	cout << "������ B(�������) ������� ��:\n";
	start = clock();
	sortMethodPuz(B, size);
	end = clock();
	outArr(B, size);
	timePuz = end - start;

	cout << "\n";

	cout << "������ �(�������) ������� ��:\n";
	start = clock();
	sortMethodInsert(C, size);
	end = clock();
	outArr(C, size);
	timeShella = end - start;

	cout << "\n";

	cout << "������ D(�������) ������� ��:\n";
	start = clock();
	sortMethodSelection(D, size);
	end = clock();
	outArr(D, size);
	timeSel = end - start;

	cout << "\n";

	cout << "������ E(�������) ������� ��:\n";
	start = clock();
	quickSort(E, 0, size - 1);
	end = clock();
	outArr(E, size);
	timeFast = end - start;

	cout << "\n";

	cout << "����� �������� ����� � " << timePuz << " ��\n"
		<< "����� ������� ����� � " << timeShella << " ��\n"
		<< "����� ������� ����� � " << timeSel << " ��\n"
		<< "������� ����� ����� � " << timeFast << " ��\n";

	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
}


//���������

void outArr(int* arr, int N)
{
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void sortMethodPuz(int* arr, int N)
{
	int buff = 0; // ��� ���������� �������� ��������, ��� ����������

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				buff = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = buff;
			}
		}
	}
}

void sortMethodInsert(int* arr, int N)
{
	int num;
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) // �������� �������������� ������� arr[j]
			// � ������ ����������� ��������� ����� �� ����
			// ���� ����������� �� �������� ������ ��� ������������
		{
			num = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}

void sortMethodSelection(int* arr, int N)
{
	int min = 0; // ��� ������ ������������ ��������
	int buf = 0; // ��� ������ ���������� 
	for (int i = 0; i < N; i++)
	{
		min = i; // �������� ����� ������� ������, ��� ������ � ����������� ���������
		// � ����� ������ �������� ����� ������ � ����������� ���������
		for (int j = i + 1; j < N; j++)
			min = (arr[j] < arr[min]) ? j : min; // ��������� �������� ������� ? ���� true : ���� false
		// ������� ������������ ����� ��������, ������� ��� ������� � �������
		if (i != min)
		{
			buf = arr[i];
			arr[i] = arr[min];
			arr[min] = buf;
		}
	}
}
void quickSort(int* arr, int first, int last)
{
	int mid, count;
	int f = first, l = last; // ��������� �� ������ � ��������� �������
	mid = arr[(f + l) / 2]; // ���������� �������� ��������
	do
	{
		while (arr[f] < mid)
			f++;
		while (arr[l] > mid)
			l--;
		if (f <= l) // ������������ ���������
		{
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
		}
	} while (f < l); // ���� right �� �������� ����� �� left
	if (first < l) quickSort(arr, first, l);
	if (f < last) quickSort(arr, f, last);
}
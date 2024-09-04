#include <iostream>
#include <ctime>

using namespace std;

unsigned long long linear(int n) 
{
    int prev = 0, current = 1;
    if (n == 1) 
    {
        return 0; // 0 1 1 2 3 5 8 13 21 34
    }
    for (int i = 2; i < n; i++) 
    {
        current += prev;
        prev = current - prev;
    }
    return current;

}


unsigned long long recursive (int n) 
{
    return n <= 1 ? n : recursive(n - 1) + recursive(n - 2); // ���� n <= 1, �� ������� n, ����� ����� ���� ����������
}


int main()
{
    setlocale(LC_ALL, "Rus");

    int way;
    cout << "�������� ������:\n 1 - �������� \n 2 - �����������" << endl;
    cin >> way;

    switch (way) 
    {
     case(1): 
        {
            int n;
            cout << "������� �������� n" << endl;
            cin >> n;
            double startTime = clock();
            cout << "�������� ����� ��������� " << n << " = " << linear(n) << endl;
            double endTime = clock();
            double resultTime = (endTime - startTime) / CLOCKS_PER_SEC;
            cout << "��������� ����� ������ " << int(resultTime) / 60 << " ����� " << float(resultTime) / 60 << " ������" << endl;
            break;
        }
     case(2): 
        {
            int n;
            cout << "������� �������� n" << endl;
            cin >> n;
            double startTime = clock();
            cout << "�������� ����� ��������� " << n << " = " << recursive(n - 1) << endl;
            double endTime = clock();
            double resultTime = (endTime - startTime) / CLOCKS_PER_SEC;
            cout << "��������� ����� ��������� " << int(resultTime) / 60 << " ����� " << float(resultTime) / 60 << " ������" << endl;
            break;
        }
     default: 
        {
            cout << "������ �����!";
        }
    }
    return 0;
}
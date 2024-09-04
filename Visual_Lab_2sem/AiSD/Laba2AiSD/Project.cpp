#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    unsigned long long n, m, min = 0, max;
    cin >> n;   max = n; m = n;
    short choice;

    do {
        n = ceil((min + max) / 2.0);
        cout << n << " \t 1 - ����, 2 - �����, 3 - ������?" << endl;
        cin >> choice;
        if (choice == 1) {
            min = n;
        }
        else {
            max = n;
        }

    } while (choice != 3);


    cout << "����� ������ �� ��������� �������� �������: \n";
    int i = 0;
    while (m != 1) {
        m = ceil(m / 2.0);
        cout << m << endl;
        i++;
    }

    cout << "���-�� �����: " << i << endl;

    return 0;
}
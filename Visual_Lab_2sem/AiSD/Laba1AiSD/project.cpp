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
    return n <= 1 ? n : recursive(n - 1) + recursive(n - 2); // если n <= 1, то вернуть n, иначе сумму двух предыдущих
}


int main()
{
    setlocale(LC_ALL, "Rus");

    int way;
    cout << "Выберите способ:\n 1 - линейный \n 2 - рекурсивный" << endl;
    cin >> way;

    switch (way) 
    {
     case(1): 
        {
            int n;
            cout << "Введите значение n" << endl;
            cin >> n;
            double startTime = clock();
            cout << "Значение числа Фибоначчи " << n << " = " << linear(n) << endl;
            double endTime = clock();
            double resultTime = (endTime - startTime) / CLOCKS_PER_SEC;
            cout << "Расчетное время циклом " << int(resultTime) / 60 << " минут " << float(resultTime) / 60 << " секунд" << endl;
            break;
        }
     case(2): 
        {
            int n;
            cout << "Введите значение n" << endl;
            cin >> n;
            double startTime = clock();
            cout << "Значение числа Фибоначчи " << n << " = " << recursive(n - 1) << endl;
            double endTime = clock();
            double resultTime = (endTime - startTime) / CLOCKS_PER_SEC;
            cout << "Расчетное время рекурсией " << int(resultTime) / 60 << " минут " << float(resultTime) / 60 << " секунд" << endl;
            break;
        }
     default: 
        {
            cout << "Ошибка ввода!";
        }
    }
    return 0;
}
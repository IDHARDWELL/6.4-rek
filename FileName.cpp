#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}


void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int Sum(int* a, int* b, const int size, int i, int sum)
{
    if (a[i] > 0)
    sum += a[i];
    if (i < size - 1)
        return Sum(a, b, size, i + 1, sum);
    else
        return sum;
}

int IFirst(int* a, const int size, int& max, int i)
{
    if (i >= size)
        return -1;

    if (abs(a[i]) > abs(max))
    {
        max = a[i];
        return i;
    }

    int index = IFirst(a, size, max, i + 1);
    return (index == -1) ? i : index;
}
int Max(int* a, const int size, int i, int max)
{
    if (i >= size)
        return max;

    if (abs(a[i]) > max)
        max = abs(a[i]);

    return Max(a, size, i + 1, max);
}



int Min(int* a, const int size, int i, int min)
{
    if (i >= size)
        return min;

    if (abs(a[i]) < min)
        min = abs(a[i]);

    return Min(a, size, i + 1, min);
}


int Pro(int* a, const int size, const int* max, const int* min, int i)
{
    if (i >= size)
        return 1;

    if (a[i] < *max && a[i] > *min)
    {
        return a[i] * Pro(a, size, max, min, i + 1);
    }

    return Pro(a, size, max, min, i + 1);
}

void Sort(int* a, const int size, int i)
{
    if (i >= size - 1)
        return;

    if (a[i] % 2 != 0) // Перевірка на непарність
    {
        int max = a[i];
        int imax = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] % 2 != 0 && max < a[j]) // Перевірка на непарність
            {
                max = a[j];
                imax = j;
            }
        }

        // Обмін елементів, якщо знайдено більший непарний
        if (imax != i)
        {
            int temp = a[i];
            a[i] = a[imax];
            a[imax] = temp;
        }
    }

    Sort(a, size, i + 1);
}


int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    int n;
    cout << "n = ";
    cin >> n;
    int* a = new int[n];
    int Low = -10;
    int High = 10;
    Create(a, n, Low, High, 0);
    cout << "Original" << endl;
    Print(a, n, 0); 
    cout << "Sum = " << Sum(a, a, n, 0, 0) << endl; // Початковий індекс та сума мають бути ініціалізовані як 0

    int maxVal = Max(a, n, 0, a[0]);
    int minVal = Min(a, n, 0 ,a[0]);
    cout << "Max = " << maxVal << endl;
    cout << "Min = " << minVal << endl;
    cout << "Prod = " << Pro(a, n, &maxVal, &minVal, 0) << endl;
    cout << "" << endl;
    cout << "Sorted" << endl;
    Sort(a, n, 0);
    Print(a, n, 0); 
    return 0;
}


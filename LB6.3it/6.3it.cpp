#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

void create(int* arr, int SIZE, int MIN, int MAX)
{
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
    }
}

void Print(int* arr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << setw(4) << arr[i];
    cout << endl;
}

int FindMin(int* arr, int SIZE)
{
    int minVal = arr[0];
    for (int i = 1; i < SIZE; i++)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }
    return minVal;
}

void PrintMatrix(int* arr, const int SIZE, const int numColumns)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(4) << arr[i];
        if ((i + 1) % numColumns == 0) 
        {
            cout << endl;
        }
    }
    if (SIZE % numColumns != 0) {
        cout << endl; 
    }
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 10;
    int MIN = -10;
    int MAX = 10;

    int* arr = new int[SIZE];
    create(arr, SIZE, MIN, MAX);

    cout << "Масив у вигляді матриці:" << endl;
    PrintMatrix(arr, SIZE, 5);
    cout << endl;

    cout << "Мінімальне значення в масиві: " << FindMin(arr, SIZE) << endl;

    create(arr, SIZE, MIN, MAX); 

    cout << "Масив у вигляді матриці після повторного створення:" << endl;
    PrintMatrix(arr, SIZE, 5); 
    cout << endl;

    cout << "Мінімальне значення у повторно створеному масиві: " << FindMin(arr, SIZE) << endl;

    delete[] arr;

    return 0;
}

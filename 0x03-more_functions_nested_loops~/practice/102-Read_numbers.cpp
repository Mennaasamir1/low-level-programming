#include "practice.h"

int ReadNumber(void)
{
    int N;

    cout << "Enter the maximum number: " << endl;
    cin >> N;

    return (N);
}

void Print_number_for_loop(int number)
{
    int i;

    for (i = 1; i <= number; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

void PrintNumbersWhileLoop(int N)
{
    int i = 1;

    while (i <= N)
    {
        cout << i << " ";
        i++;
    }
    cout << "\n";
}

void PrintNumbersDoWhileLoop(int N)
{
    int i = 1;

    do
    {
        cout << i << " ";
        i++;
    } while (i <= N);

    cout << "\n";
    
}

int main(void)
{
    int Number = ReadNumber();

    Print_number_for_loop(Number);
    PrintNumbersWhileLoop(Number);
    PrintNumbersDoWhileLoop(Number);

    return (0);
}
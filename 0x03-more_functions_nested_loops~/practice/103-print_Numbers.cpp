#include "practice.h"

int Read_numberFromUser(void)
{
    int num;

    cout << "Enter a number (numbers will be printed in descendent order): ";
    cin >> num;

    return (num);
}

void PrintNumbersFrom_N_To_1WhileLoop(int N)
{
    int i = N;

    cout << "\nPrinting numbers using while loop" << endl;
    while (i >= 1)
    {
        cout << i << " ";
        i--;
    }
    cout << "\n";
}

void PrintNumbersFromNto1_forloop(int N)
{
    int i;

    cout << "\nprinting numbers using for loop\n";
    for (i = N; i >= 1; i--)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void PrintNumbersFromNto1_doWhileloop(int N)
{
    int i = N;

    cout << "\nprinting numbers using do while loop\n";
    do
    {
        cout << i << " ";
        i--;

    } while (i >= 1);
    cout << "\n";
    
}
int main(void)
{
    int N = Read_numberFromUser();

    PrintNumbersFrom_N_To_1WhileLoop(N);
    PrintNumbersFromNto1_forloop(N);
    PrintNumbersFromNto1_doWhileloop(N);

    return (0);
}
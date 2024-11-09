#include "practice.h"

void ReadNumbers(int &N1, int &N2)
{
    cout << "Enter number1: " << endl;
    cin >> N1;

    cout << "Enter number2: " << endl;
    cin >> N2;
}

void SwapNumbers(int &N1, int &N2)
{
    int temp;

    temp = N1;
    N1 = N2;
    N2 = temp;
}

void PrintResult(int num1, int num2)
{
    cout << "\nNum1 = " << num1 << endl;
    cout << "Num2 = " << num2 << endl;
}

int main(void)
{
    int num1, num2;

    ReadNumbers(num1, num2);

    PrintResult(num1, num2);

    SwapNumbers(num1, num2);

    PrintResult(num1, num2);

    return (0);
}
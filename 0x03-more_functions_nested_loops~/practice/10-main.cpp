#include "practice.h"

void Read_numbers(int &number1, int &number2, int &number3)
{
    cout << "Enter number 1: " <<  endl;
    cin >> number1;

    cout << "Enter number 2: " << endl;
    cin >> number2;

    cout << "Enter number 3: " << endl;
    cin >> number3;
}

int MaxOf3Numbers(int num1, int num2, int num3)
{
    if (num1 > num2)
    {
        if (num1 > num3)
            return (num1);
        else
            return (num3);
    }
    else
    {
        if (num2 > num3)
            return (num2);
        else
            return (num3);
    }
}

void print_result(int MaxNum)
{
    cout << "\nThe maximum number is: " << MaxNum << endl;
}
int main(void)
{
    int num1, num2, num3;

    Read_numbers(num1, num2, num3);
    print_result(MaxOf3Numbers(num1, num2, num3));

    return (0);
}
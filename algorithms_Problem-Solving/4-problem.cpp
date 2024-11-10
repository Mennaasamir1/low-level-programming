#include "main.h"

/**
 * ReadAPositivenumber - asks the user to enter a positive number.
 *
 * Return: input number
 */
int ReadAPositivenumber(void)
{
    int i;

    do
    {
        cout << "Enter a positive number: ";
        cin >> i;
    } while (i <= 0);

    return (i);
}

/**
 * PrintReversedDigits - reverses the number's digits
 * @Number: number whose digits to be reversed
 */
void PrintReversedDigits(int Number)
{
    int ReversedNum = 0;

    while (Number > 0)
    {
        ReversedNum = Number % 10;
        Number = Number / 10;
        cout << ReversedNum << endl;
    }
}
#include "main.h"

/**
 * ReadAPositivenumberAndDigit - asks the user to enter a positive number.
 *
 * Return: input number
 */
int ReadAPositivenumber2(string Message)
{
    int i;

    do
    {
        cout << Message;
        cin >> i;
    } while (i <= 0);

    return (i);
}

/**
 * ReverseNumber - reverses a number's digits
 * @Number: input number
 * Return: Reversed number
 */

int ReverseNumber(int Number)
{
    int LastDigit = 0, ReversedNum = 0;

    while (Number > 0)
    {
        LastDigit = Number % 10;
        Number = Number / 10;
        ReversedNum = ReversedNum * 10 + LastDigit;
    }
    return (ReversedNum);
}
/**
 * PrintDigitsInOrder - prints numbers in reverse
 * @Number: input number
 */
void PrintDigitsInOrder(int Number)
{
    int lastDigit = 0;

    while (Number > 0)
    {
       lastDigit = Number % 10;
       Number = Number / 10;
       cout << lastDigit << endl;
    }
}
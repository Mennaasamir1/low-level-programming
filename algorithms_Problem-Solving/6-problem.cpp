#include "main.h"

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
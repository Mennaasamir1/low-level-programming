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

int DigitFrequency(int Number, short Digit)
{
    int LastDigit = 0, Frequency = 0;

    while (Number > 0)
    {
        LastDigit = Number % 10;
        Number = Number / 10;
        if (Digit == LastDigit)
        {
            Frequency++;
        }
    }
    return (Frequency);
}
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
 * PrintInvertedNumber - prints inverted number pattern
 * @N: input number
 */
void PrintInvertedNumber(int N)
{
    int line, i;

    cout << endl;
    for (line = N; line >= 1; line--)
    {
        for (i = 1; i <= line; i++)
        {
            cout << line;
        }
        cout << endl;
    }
}
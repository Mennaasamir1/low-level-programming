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
 * PrintAlphabetPattern - prints a regular alphabet pattern
 * @Number: input number
 */
void PrintAlphabetPattern(int Number)
{
    int row, col;

    cout << endl;
    for (row = 65; row <= 65 + Number - 1; row++)
    {
        for (col = 1; col <= Number - (65 + Number - 1 - row); col++)
        {
            cout << char(row);
        }
        cout << endl;
    }
}
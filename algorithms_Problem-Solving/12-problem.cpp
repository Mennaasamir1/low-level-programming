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
 * PrintNumberPattern - prints normal number pattern (not inverted)
 * @Number: input number
 */
void PrintNumberPattern(int Number)
{
    int line, col;

    cout << endl;
    for (line = 1; line <= Number; line++)
    {
        for (col = 1; col <= line; col++)
        {
            cout << line;
        }
        cout << endl;
    }
}
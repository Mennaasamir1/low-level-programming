#include "main.h"
/**
 * print_line -  draws a straight line in the terminal using the character _,
 * followed by a new line
 * @n: length of line
 */
void print_line(int n)
{
    int i;

    if (n <= 0)
    {
        cout << "\n";
    }

    for (i = 0; i < n; i++)
    {
        cout << '_';
    }
    cout << "\n";
}
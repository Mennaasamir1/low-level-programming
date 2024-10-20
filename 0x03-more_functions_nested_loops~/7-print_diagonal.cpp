#include "main.h"
/**
 * print_diagonal - prints a diagonal in the terminal
 * @n: length of diagonal
 */
void print_diagonal(int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            cout << ' ';
        }
    }
    cout << "\\" << "\n";
}
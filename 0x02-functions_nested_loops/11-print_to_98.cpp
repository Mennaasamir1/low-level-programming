#include "main.h"
/**
 * print_to_98 - prints natural numbers up to 98
 * @n: number to start counting from
 */
void print_to_98(int n)
{
    int count;

    if (n <= 0)
    {
        cout << "This cannot be applied. natural numbers start from 1\n";
    }
    else
    {
        for (count = n; count < 99; count++)
        {
            cout << count;
            if (count != 98)
            {
                cout << ", ";
            }
        }
        cout << "\n";
    }
}
#include "main.h"
/**
 * print_sign - prints a number's sign
 * @n: number
 * Return: 0, 1, or -1
 */
int print_sign(int n)
{
    if (n == 0)
    {
        cout << 0 << endl;
        return (0);
    }
    else if (n > 0)
    {
        cout << "+" << endl;
        return (1);
    }
    else
    {
        cout << "-"  << endl;
        return (-1);
    }

}
#include "main.h"
/**
 * _abs - returns the absolute value of a number.
 * @n: number
 * Return: the absolute value of number
 */
int _abs(int n)
{
    if (n < 0)
    {
        return (n * -1);
    }
    else if (n == 0)
    {
        return (0);
    }
    else
    {
        return (n);
    }
}
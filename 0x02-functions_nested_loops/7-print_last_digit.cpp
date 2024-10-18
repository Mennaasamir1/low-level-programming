#include "main.h"
/**
 * print_last_digit - prints the last digit of a number
 * @n: number
 * Return: the value of the last digit
 */
int print_last_digit(int n)
{
    int lastDigit;

    if (n < 0)
    {
        lastDigit = -1 * (n % 10);
    }
    else
    {
        lastDigit = n % 10;
    }

    cout << "The last digit of " << n << " is " << lastDigit << endl;

    return (lastDigit);
}
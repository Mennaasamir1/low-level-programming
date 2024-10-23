#include "main.h"
/**
 * main - program that prints any integer without using long or arrays/
 *
 * Return: 0 or 1
 */
int main(void)
{
    unsigned number = 887980809;
    unsigned count, m, divisor;

    if (number < 0)
    {
        cout << '-';
        m = number * -1;
    }
    else
    {
        m = number;
    }

    divisor = m;
    count = 1;
    
    while (divisor > 9)
    {
        divisor /= 10;
        count *= 10;
    }
    for (; count >= 1; count /= 10)
    {
        cout << (m / count) % 10;
    }
    cout << "\n";

    return (0);
}
#include "main.h"
/**
 * main - program that prints the sum of even-valued
 * Fibonacci numbers not exceeding 4,000,000
 *
 * Return: 0 or 1
 */
int main(void)
{
    int i, prev = 0, next = 1, result, sum = 0;

    for (i = 0; i < 49; i++)
    {
        
        if (next % 2 == 0 && next <= 4000000)
        {
            sum += next;
        }
        result = prev + next;
        prev = next;
        next = result;
    }
    cout << "sum of even valued numbers not exceeding 4 million = " << sum << endl;

    return (0);
}
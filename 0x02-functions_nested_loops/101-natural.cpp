#include "main.h"
/**
 * main -  program that computes and prints the sum of
 * all multiples of 3 or 5 below 1024
 *
 * Return: 0 or 1
 */
int main(void)
{
    int i, sum = 0;

    for (i = 1; i < 1024; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            sum += i;
        }
    }
    cout << "sum is " << sum << endl;

    return (0);
}
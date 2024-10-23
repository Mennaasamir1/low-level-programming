#include "main.h"
/**
 * main - prints the largest "prime" factor of a number
 *
 * Return: 0 or 1
 */
int main(void)
{
    long number = 612852475143, PF;

    for (PF = 2; PF <= number; PF++)
    {
        if (number % PF == 0)
        {
            number /= PF;
            PF--;
        }
    }
    cout << "The largest prime factor is: " << PF << endl;
    return (0);
}
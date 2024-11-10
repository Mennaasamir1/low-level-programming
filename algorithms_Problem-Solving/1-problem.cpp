#include "main.h"

/**
 * ReadAPositivenumber - asks the user to enter a positive number
 * Return: entered number
 */
int ReadAPositivenumber(void)
{
    int i;

    do
    {
        cout << "Enter a positive number: ";
        cin >> i;
    } while (i <= 0);

    return (i);
}
/**
 * CheckPrimeNumber - checks if a number is a prime number or not
 * @number: number from 1 to N
 * Return: is prime or not
 */
enIsPrime CheckPrimeNumber(int number)
{
    int i;
    int M = round(number / 2);

    for (i = 2; i <= M; i++)
    {
        if (number % i == 0)
            return (enIsPrime::NotPrime);
    }
    return (enIsPrime::Prime);
}

/**
 * PrintPrimeNumbers - prints prime numbers from 1 to N (specific number)
 * @N: specific number enterd by the user
 */
void PrintPrimeNumbers(int N)
{
    int num;

    for (num = 1; num <= N; num++)
    {
        if (CheckPrimeNumber(num) == enIsPrime::Prime)
            cout << num << endl;
    }
}
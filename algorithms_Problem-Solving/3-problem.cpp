#include "main.h"

/**
 * ReadAPositivenumber - asks the user to enter a positive number.
 *
 * Return: input number
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
 * CheckPerfectNumber - checks if a number is perfect or not
 * Perfect number: a number is perfect when 
 * the sum of all its divisors(except the number itself) == the number itself
 * 
 * @number: number to be checked
 * Return: sum of the number's divisors
 */
bool CheckPerfectNumber(int number)
{
    int counter, Sum = 0;

    for (counter = 1; counter < number; counter++)
    {
        if (number % counter == 0)
        {
            Sum += counter;
        }
    }
    return (number == Sum); /* = if num == sum => return true*/
}

/**
 * PrintAllPerfectNumbers - prints all the perfect numbers from 1 => N
 * @N: number
 */
void PrintAllPerfectNumbers(int N)
{
    int i;

    cout << "\nperfect numbers from 1 to " << N << ": " << endl;
    for (i = 1; i <= N; i++)
    {
        if (CheckPerfectNumber(i))
            cout << i << endl;
    }
}
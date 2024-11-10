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
 * PrintPerfectOrNot - prints if a number is perfect or not
 * @number: number to be checked
 */
void PrintPerfectOrNot(int Number)
{
    if (CheckPerfectNumber(Number))
        cout << endl << Number << " is perfect\n";
    else
        cout << endl << Number << " is not perfect\n";
}
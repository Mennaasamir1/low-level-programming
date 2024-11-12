#include "main.h"

/**
 * ReadAPositivenumber - reads a positive number
 *
 * Return: positive number
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
 * SumOfDigits - sums the digits of a number
 * @number: input number
 * Return: sum of digits
 */
int SumOfDigits(int number)
{
    int sum = 0, DigitsOfNumber = 0;

    while (number > 0)
    {
        DigitsOfNumber = number % 10;
        number = number / 10;
        sum += DigitsOfNumber;
    }
    return (sum);
}
/**
 * printSumOfDigits - Prints the sum of digits to the stdout
 * @Number: input number
 */
void printSumOfDigits(int Number)
{
    cout << "\nThe sum of the digits of " << Number << " = " << SumOfDigits(Number) << endl;
}
#include "practice.h"

/**
 * enum enNumber - assigns values to odd numbers and even numbers
 * @odd: odd numbers
 * @even: even numbers
 */
enum enNumber {odd = 1, even = 2};

/**
 * Read_number - reads number from user
 *
 * Return: input number
 */
int Read_number(void)
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    return (number);
}

/**
 * check_number_type - checks number type (odd or even)
 * @number: number
 * Return: number type
 */
enNumber check_number_type(int number)
{
    int result = number % 2;

    if (result == 0)
    {
        return (enNumber::even);
    }
    else
    {
        return (enNumber::odd);
    }
}
/**
 * print_number_type - prints number type
 * @number_Type: number type
 */
void print_number_type(enNumber number_Type)
{
    if (number_Type == enNumber::even)
    {
        cout << "The number is even\n";
    }
    else
    {
        cout << "The number is odd\n";
    }
}
/**
 * main - entry point
 *
 * Return: 0 or 1
 */
int main(void)
{
    print_number_type(check_number_type(Read_number()));

    return (0);
}
#include "main.h"
/**
 * main - entry point
 *
 * Return: 0 or 1
 */
int main(void)
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << "the absolute value of " << number << " is " << _abs(number) << endl;

    return (0);
}
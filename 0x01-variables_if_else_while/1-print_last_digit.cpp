#include "main.h"
/**
 * print_last_digit - prints the last digit of a random number
 * and checks if the last digit is greater than 5 or not.
 *
 * @number: the randomly generated number.
 */
void print_last_digit(int number)
{
    int last_digit;

    last_digit = number % 10;

    cout << "last digit of " << number << " is " << last_digit;

    if (last_digit < 6 && last_digit != 0)
    {
        cout << " and is less than 6 and not 0" << endl;
    }
    else
    {
      cout << " and is greater than 5." << endl;
    }

}
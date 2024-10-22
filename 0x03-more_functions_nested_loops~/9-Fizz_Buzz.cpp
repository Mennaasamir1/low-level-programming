#include "main.h"
/**
 * main - program that prints numbers from 1 to 100 but for multiples of
 * 3 => prints Fizz, multiples of 5 => prints Buzz, and for multiples of
 * both => prints FizzBuzz, otherwise it prints the number
 *
 * Return: 0 if success, otherwise 1
 */
int main(void)
{
    short number;

    for (number = 1; number <= 100; number++)
    {
        if ((number % 3 == 0) && (number % 5 == 0))
        {
            cout << "FizzBuzz" << " ";
        }
        else if (number % 3 == 0)
        {
            cout << "Fizz" << " ";
        }
        else if (number % 5 == 0)
        {
            cout << "Buzz" << " ";
        }
        else
        {
            cout << number << " ";
        }
    }
    cout << "\n";

    return (0);
}
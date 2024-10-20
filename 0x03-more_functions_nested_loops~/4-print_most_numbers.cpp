#include "main.h"
/**
 * print_most_numbers - prints the numbers 0 to 9 except for 2 and 4, followed by a new line.
 */
void print_most_numbers(void)
{
    short number;

    for (number = 0; number < 10; number++)
    {
        if (number == 2 || number == 4)
        {
            continue;
        }
        cout << number;
    }
    cout << "\n";
}
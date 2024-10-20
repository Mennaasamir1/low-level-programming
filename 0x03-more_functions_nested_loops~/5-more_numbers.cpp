#include "main.h"
/**
 * more_numbers - prints the numbers 0 to 14, followed by a new line, ten times.
 */
void more_numbers(void)
{
    short number, counter;

    for (counter = 0; counter < 10; counter++)
    {
        for (number = 0; number <= 14; number++)
        {
            cout << number;
        }
        cout << "\n";
    }
}
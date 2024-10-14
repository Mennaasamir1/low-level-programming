#include "main.h"
/**
 * Is_positive_or_Negative - checks if the random number
 * is positive or negative or zero and prints the answer accordingly
 *
 */
void Is_positive_or_Negative(void)
{
    short number;

    srand(time(0));
    number = rand();

    if (number < 0)
    {
        cout << number << " is negative." << endl;
    }
    else if (number > 0)
    {
        cout << number << " is positive." << endl;
    }
    else
    {
        cout << number << " is zero." << endl;
    }
}
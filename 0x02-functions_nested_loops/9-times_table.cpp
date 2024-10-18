#include "main.h"
/**
 * times_table - prints the 9 times table
 */
void times_table(void)
{
    int i, result;

    for (i = 0; i < 13; i++)
    {
        result = 9 * i;
        cout << 9 << " * " << i << " = " << result << endl;
    }
}
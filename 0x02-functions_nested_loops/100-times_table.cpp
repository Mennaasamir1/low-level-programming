#include "main.h"

void print_times_table(int n)
{
    int i;

    if (n > 15 || n < 0)
    {
        cout << "\n";
    }
    else
    {
        for (i = 0; i < 13; i++)
        {
            cout << n << " * " << i << " = " << n * i << endl;
        }
    }
}
#include "main.h"
/**
 * print_square - prints a square using '#' character
 * @size: size of square
*/
void print_square(int size)
{
    int rows, cols;

    if (size <= 0)
    {
        cout << "\n";
    }
    for (rows = 0; rows < size; rows++)
    {
        for (cols = 0; cols < size; cols++)
        {
            cout << "#";
        }
        cout << "\n";
    }
}
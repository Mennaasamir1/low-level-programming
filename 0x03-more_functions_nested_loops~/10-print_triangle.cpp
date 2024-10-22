#include "main.h"
/**
 * print_triangle - prints a trianle using the '#' character.
 * @size: size of triangle
 */
void print_triangle(int size)
{
    int rows, cols, i;

    if (size <= 0)
    {
        cout << "\n";
    }

    for (rows = 0; rows < size; rows++)
    {
        for (cols = size - 1; cols > rows; cols--)
        {
            cout << ' ';
        }
        for (i = 0; i < cols + 1; i++)
        {
            cout << "#";
        }
        cout << "\n";
        
    }

}
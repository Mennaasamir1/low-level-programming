#include "main.h"
/**
 * main - entry point
 *
 * Return: 0 or 1
 */
int main(void)
{
    int SizeOfTriangle;

    cout << "Enter size of triangle: ";
    cin >> SizeOfTriangle;

    print_triangle(SizeOfTriangle);

    return (0);
}
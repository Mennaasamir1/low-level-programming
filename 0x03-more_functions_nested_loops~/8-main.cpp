#include "main.h"
/**
 * main - entry point
 *
 * Return: 0 or 1
 */
int main(void)
{
    int sizeOfSquare;

    cout << "Enter size of square: ";
    cin >> sizeOfSquare;

    print_square(sizeOfSquare);

    return (0);
}
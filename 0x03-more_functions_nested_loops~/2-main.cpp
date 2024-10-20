#include "main.h"
/**
 * main - entry point of the program
 *
 * Return: 0 or 1
 */
int main(void)
{
    int first, second;

    cout << "Enter 2 integers:" << endl;
    cin >> first;
    cin >> second;

    cout << first << " * " << second << " = " << mul(first, second) << endl;

    return (0);
}
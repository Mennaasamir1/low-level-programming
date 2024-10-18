#include "main.h"
/**
 * main - entry point
 *
 * Return: 0 or 1
 */
int main(void)
{
    int n;

    cout << "Enter any number: ";
    cin >> n;

    print_last_digit(n);

    return (0);
}
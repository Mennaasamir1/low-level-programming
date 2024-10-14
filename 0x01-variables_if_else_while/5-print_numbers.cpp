#include "main.h"
/**
 * main - a program that prints all single digit numbers starting from 0
 *
 * Return: 0 or 1.
 */
int main(void)
{
    short num = 0;

    while (num < 10)
    {
        cout << num;
        num++;
    }
    cout << "\n";

    return (0);
}
#include "main.h"
/**
 * main - prints numbers of base 16.
 *
 * Return: 0 0r 1.
 */
int main(void)
{
    int Hex_num = 0;

    while (Hex_num < 10)
    {
        cout << Hex_num;
        Hex_num++;
    }

    Hex_num = 97;

    while (Hex_num <= 102)
    {
        cout << char(Hex_num);
        Hex_num++;
    }
    cout << "\n";

    return (0);
}
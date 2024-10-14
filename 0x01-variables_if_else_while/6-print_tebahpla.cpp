#include "main.h"
/**
 * main - prints the lowercase alphabets in reverse
 * 
 * Return: 0 or 1
 */

int main(void)
{
    short alphabet = 122;

    while (alphabet >= 97)
    {
        cout << char(alphabet);
        alphabet--;
    }
    cout << "\n";
    return (0);
}
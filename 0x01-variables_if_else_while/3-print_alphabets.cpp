#include "main.h"
/**
 * print_lower_upper_alphabets - prints the uppercase and lowercase alphabets.
 */
void print_lower_upper_alphabets(void)
{
    short alphabet = 97;

    while (alphabet >= 97 && alphabet <= 122)
    {
        cout << char(alphabet);
        alphabet++;
    }

    alphabet = 65;
    while (alphabet >= 65 && alphabet <= 90)
    {
        cout << char (alphabet);
        alphabet++;
    }
    cout << "\n";
}
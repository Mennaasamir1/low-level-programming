#include "main.h"
/**
 * print_lowercase_alphabet - prints the lowercase alphabets.
 */
void print_lowercase_alphabet(void)
{
    int alphabet = 97;

    while (alphabet >= 97 && alphabet <= 122)
    {
        cout << char(alphabet) << " ";
        alphabet++;
    }
    cout << "\n";
}
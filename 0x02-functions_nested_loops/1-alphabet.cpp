#include "main.h"
/**
 * Print_lowercase_alphabet - prints the alphabet in lowercase.
 */
void Print_lowercase_alphabet(void)
{
    short alphabet;

    for (alphabet = 97; alphabet <= 122; alphabet++)
    {
        cout << char(alphabet);
    }
    cout << "\n";
}
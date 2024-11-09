#include "practice.h"

void PrintLetters(void)
{
    int letter;

    cout << "\nCapital letters => ";
    for (letter = 65; letter <= 90; letter++)
    {
        cout << char(letter);
    }
    cout << endl;

    cout << "Small letters => ";
    for (letter = 97; letter <= 122; letter++)
    {
        cout << char(letter);
    }
    cout << endl;
}

int main(void)
{
    PrintLetters();

    return (0);
}
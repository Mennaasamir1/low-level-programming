#include "MyHeader.h"

int main(void)
{
    char C;

    cout << "Enter a character: ";
    cin >> C;

    cout << "\nCharacter after being inverted: " << MyHeader::InvertCharacter(C) << endl;

    return (0);
}
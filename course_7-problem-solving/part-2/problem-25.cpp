#include "MyHeader.h"

int main(void)
{
    string MyString = MyHeader::ReadString();
    string Upper = MyHeader::StringToUpper(MyString);
    string Lower = MyHeader::StringToLower(MyString);
    char C = 'A';

    cout << "\nString in uppercase: ";
    cout << endl << Upper << endl;

    cout << "\nString in lowercase: ";
    cout << endl << Lower << endl;

    cout << MyHeader::InvertCharacter(C);

    return (0);
}
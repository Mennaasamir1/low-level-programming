#include "MyHeader.h"

int main(void)
{
    string MyString = MyHeader::ReadString();

    cout << "\nString before capialization: " << MyString << endl;
    /* MyHeader::PrintFirstLetters(MyString); */
    MyString = MyHeader::UpperCaseFirstLetter(MyString);

    cout << MyString << endl;

    return (0);
}
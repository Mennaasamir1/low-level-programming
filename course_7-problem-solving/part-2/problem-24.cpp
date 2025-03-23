#include "MyHeader.h"

int main(void)
{
    string MyString = MyHeader::ReadString();

    cout << "\nConverting string to lowecase..." << endl;

    MyString = MyHeader::LowerCaseFirstLetter(MyString);

    cout << endl << MyString << endl;

    return (0);
}
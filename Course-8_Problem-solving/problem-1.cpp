#include "MyHeader.h"

int main(void)
{
    int Number = MyHeader::ReadNumber("Enter a number: ");

    cout << MyHeader::NumberToText(Number) << endl;

    return (0);
}
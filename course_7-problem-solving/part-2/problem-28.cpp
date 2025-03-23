#include "MyHeader.h"

int main(void)
{
    string S = MyHeader::ReadString();

    cout << "\nString in lowercase: " << S << endl;

    S = MyHeader::InvertAllLetters(S);

    cout << "\nString in uppercase: " << S << endl;

    return (0);
}
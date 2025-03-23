#include "MyHeader.h"

int main(void)
{
    string S = MyHeader::ReadString();
    char C = MyHeader::ReadCharacter();

    cout << "\nletter \"" << C << "\"" << ", Count = " << MyHeader::CountLetterInWord(S, C) << endl;
 
    return (0);
}
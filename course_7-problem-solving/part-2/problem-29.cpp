#include "MyHeader.h"

int main(void)
{
    string My_string = MyHeader::ReadString();

    cout << "\nString Length: " << MyHeader::CountAllLetters(My_string) << endl;

    cout << "\nCapital letters count: "
        << MyHeader::CountAllLetters(My_string, enWhatToCount::Capital) << endl;
    
    cout << "\nSmall letters count: "
        << MyHeader::CountAllLetters(My_string, enWhatToCount::Small) << endl;

    return (0);
}
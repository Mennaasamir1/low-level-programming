#include "MyHeader.h"

int main(void)
{
    cout << "\nEnter Date1:" << endl;
    stDate Date1 = MyHeader::ReadFullDate();

    cout << "\nEnter Date2:" << endl;
    stDate Date2 = MyHeader::ReadFullDate();

    cout << "\nComparison Result = " << MyHeader::CompareDates(Date1, Date2) << endl;

    return (0);
}
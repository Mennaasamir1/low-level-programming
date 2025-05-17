#include "MyHeader.h"

int main(void)
{
    cout << "\nEnter Date1:" << endl;
    stDate Date1 = MyHeader::ReadFullDate();

    cout << "\nEnter Date2:" << endl;
    stDate Date2 = MyHeader::ReadFullDate();

    if (MyHeader::IsDate1AfterDate2(Date1, Date2))
    {
        cout << "\nYes Date1 is after Date2." << endl;
    }
    else
    {
        cout << "\nNo Date1 is not after Date2" << endl;
    }

    return (0);
}
#include "MyHeader.h"

int main(void)
{
    stDate Date1 = MyHeader::ReadFullDate();
    stDate Date2 = MyHeader::ReadFullDate();

    if (MyHeader::IsDate1BeforeDate2(Date1, Date2))
    {
        cout << "\nYes. Date1 is before Date2" << endl;
    }
    else
    {
        cout << "\nNo. Date1 is not before Date2" << endl;
    }

    return (0);
}
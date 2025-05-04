#include "MyHeader.h"

int main(void)
{
    short Year = MyHeader::ReadNumber("Enter a year to check: ");

    if (MyHeader::LeapYearOrNot(Year))
    {
        cout << endl << Year << " is a leap year." << endl;
    }
    else
    {
        cout << endl << Year << " is not a leap year." << endl;
    }

    return (0);
}
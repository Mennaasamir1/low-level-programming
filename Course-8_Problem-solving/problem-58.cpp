#include "MyHeader.h"

int main(void)
{
    stPeriod Period1, Period2;

    cout << "\nEnter Period1:" << endl;
    Period1 = MyHeader::ReadPeriod();

    cout << "\nEnter Period2:" << endl;
    Period2 = MyHeader::ReadPeriod();

    if (MyHeader::IsPeriodOverlap(Period1, Period2))
    {
        cout << "\nYES. periods overlap." << endl;
    }
    else
    {
        cout << "\nNO. Periods do not overlap." << endl;
    }

    return (0);
}
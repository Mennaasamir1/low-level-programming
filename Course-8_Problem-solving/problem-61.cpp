#include "MyHeader.h"

int main(void)
{

    cout << "\nEnter Period1:" << endl;
    stPeriod Period1 = MyHeader::ReadPeriod();

    cout << "\nEnter Period2:" << endl;
    stPeriod Period2 = MyHeader::ReadPeriod();

    cout << "\nOverlap days count: " << MyHeader::GetOverLappedDaysNum(Period1, Period2) << endl;

    return (0);
}
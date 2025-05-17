#include "MyHeader.h"

int main(void)
{
    stPeriod Period;
    stDate DateToCheck;

    cout << "\nEnter Period:" << endl;
    Period = MyHeader::ReadPeriod();

    cout << "\nEnter Date to check:" << endl;
    DateToCheck = MyHeader::ReadFullDate();

    if (MyHeader::IsWithinPeriod(Period, DateToCheck))
    {
        cout << "\nYes, date is within period." << endl;
    }
    else
    {
        cout << "\nNo, date is not within period." << endl;
    }

    return (0);
}
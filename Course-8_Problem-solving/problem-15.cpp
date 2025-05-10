#include "MyHeader.h"

int main(void)
{
    stDate Date;
    Date = MyHeader::ReadFullDate();

    if (MyHeader::IsLastDayInMonth(Date))
    {
        cout << "\nYes it's the last day in month" << endl;
    }
    else
    {
        cout << "\nNo, it's not the last day in month" << endl;
    }

    if (MyHeader::IsLastMonthInYear(Date.Month))
    {
        cout << "\nYes, it's the last month of the year" << endl;
    }
    else
    {
        cout << "\nNo, it's not the last month of the year" << endl;
    }
    return (0);
}
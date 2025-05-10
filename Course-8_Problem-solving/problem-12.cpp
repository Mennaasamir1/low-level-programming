#include "MyHeader.h"

int main(void)
{
    stDate Date = MyHeader::ReadFullDate();
    short DaysTobeAdded = MyHeader::ReadDays();

    Date = MyHeader::AddDaysToDate(DaysTobeAdded, Date);
    cout << "\nThe exact date after " << DaysTobeAdded << " is "
        << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    return (0);
}
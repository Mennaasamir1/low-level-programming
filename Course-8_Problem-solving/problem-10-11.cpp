#include "MyHeader.h"

int main(void)
{
    short Day = MyHeader::ReadNumber("Enter Day: ");
    short Month = MyHeader::ReadNumber("Enter month: ");
    short Year = MyHeader::ReadNumber("Enter Year: ");
    short TotalDays = MyHeader::TotalDaysFromBeginningOfYear(Day, Month, Year);
    stDate Date;

    cout << "\nNumber of days from the beginning of the year is "
        << TotalDays << endl;

    Date = MyHeader::GetTheExactDate(TotalDays, Year);
    cout << "\nDate: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    return (0);
}
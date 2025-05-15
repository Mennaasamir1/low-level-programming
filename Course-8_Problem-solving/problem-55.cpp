#include "MyHeader.h"

int main(void)
{
    stDate DateFrom = MyHeader::ReadFullDate();
    short VacationDays = MyHeader::ReadNumber("Enter vacation days: ");

    DateFrom = MyHeader::CalculateVacationReturn(DateFrom, VacationDays);
    cout << "\nYour return date is: " << MyHeader::WeekDayName(MyHeader::WeekDayOrder(DateFrom))
        << " , " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;

    return (0);
}
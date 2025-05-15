#include "MyHeader.h"

int main(void)
{
    stDate Date = MyHeader::GetSystemDate();

    cout << "\nToday is " << MyHeader::WeekDayName(MyHeader::WeekDayOrder(Date))
        << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    cout << "\nIs it End of week?" << endl;
    if (MyHeader::IsEndOfWeek(Date))
    {
        cout << "yes it is end of week." << endl;
    }
    else
    {
        cout << "No it is not end of week." << endl;
    }

    cout << "\nIs it Weekend?" << endl;
    if (MyHeader::IsWeekEnd(Date))
    {
        cout << "Yes it is weekend." << endl;
    }
    else
    {
        cout << "No it is not weekend." << endl;
    }

    cout << "\nIs it a business day?" << endl;
    if (MyHeader::IsBusinessDay(Date))
    {
        cout << "yes it is a business day." << endl;
    }
    else
    {
        cout << "No it is not a business day." << endl;
    }

    cout << "\nDays until end of week: " << MyHeader::DaysUntilEndOfWeek(Date) << " Day(s)." << endl;
    cout << "Days until end of month: " << MyHeader::DaysUntilEndOfMonth(Date) << " Day(s)." << endl;
    cout << "Days until end of year: " << MyHeader::DaysUntilEndOfYear(Date) << " Day(s)." << endl;
    return (0);
}
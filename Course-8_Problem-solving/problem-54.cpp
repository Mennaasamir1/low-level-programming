#include "MyHeader.h"

int main(void)
{
    cout << "\nVacation starts:" << endl;
    stDate StartDate = MyHeader::ReadFullDate();

    cout << "\nVacation ends:" << endl;
    stDate EndDate = MyHeader::ReadFullDate();

    cout << "\nVacation from: " << MyHeader::WeekDayName(MyHeader::WeekDayOrder(StartDate)) << " , "
        << StartDate.Day << "/" << StartDate.Month << "/" << StartDate.Year << endl;
    
    cout << "Vacation to: " << MyHeader::WeekDayName(MyHeader::WeekDayOrder(EndDate)) << " , "
        << EndDate.Day << "/" << EndDate.Month << "/" << EndDate.Year << endl;
    
    cout << "\nActual vacation days: " << MyHeader::ActualVacationDays(StartDate, EndDate) << endl;
    return (0);
}
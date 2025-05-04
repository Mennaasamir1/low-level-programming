#include "MyHeader.h"

int main(void)
{
    short Year = MyHeader::ReadNumber("Enter a year: ");
    short Month = MyHeader::ReadNumber("\nEnter a month: ");

    cout << "\nNumber of days in Month [" << Month << "]: "
        << MyHeader::NumberOfDaysInMon(Month, Year) << endl;
    
    cout << "\nNumber of hours in Month [" << Month << "]: "
        << MyHeader::NumberOfHoursInMonth(Month, Year) << endl;

    cout << "\nNumber of minutes in Month [" << Month << "]: "
        << MyHeader::NumberOfMinsInMonth(Month, Year) << endl;

    cout << "\nNumber of seconds in Month [" << Month << "]: "
        << MyHeader::NumberOfSecsInMonth(Month, Year) << endl;

    return (0);
}
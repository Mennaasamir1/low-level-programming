#include "MyHeader.h"

int main(void)
{
    short Year = MyHeader::ReadNumber("Enter Year: ");
    short Month = MyHeader::ReadNumber("\nEnter Month: ");
    short Day = MyHeader::ReadNumber("\nEnter Day: ");

    cout << "\nDate: " << Day << "/" << Month << "/" << Year << endl;
    cout << "\nDay order: " << MyHeader::WeekDayOrder(Day, Month, Year) << endl;
    cout << "\nDay Name: " << MyHeader::WeekDayName(MyHeader::WeekDayOrder(Day, Month, Year)) << endl;

    return (0);
}
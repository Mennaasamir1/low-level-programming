#include "MyHeader.h"

int main(void)
{
    short Month = MyHeader::ReadNumber("Enter Month: ");
    short Year = MyHeader::ReadNumber("Enter Year: ");

    MyHeader::PrintMonthCalender(Month, Year);

    return (0);
}
#include "MyHeader.h"

int main(void)
{
    short Year = MyHeader::ReadNumber("Enter Year: ");

    MyHeader::PrintYearCalender(Year);

    return (0);
}
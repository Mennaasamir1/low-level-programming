#include "MyHeader.h"

int main(void)
{
    short Year = MyHeader::ReadNumber("Enter a year: ");

    cout << "\nNumber of Days in "  << Year  << " is "<< MyHeader::CalculateNumberOfDays(Year) << endl;
    cout << "\nNumber of Hours in " << Year << " is " << MyHeader::CalcNumberOfHours(Year) << endl;
    cout << "\nNumber of Minutes in " << Year << " is " << MyHeader::CalcNumberOfMins(Year) << endl;
    cout << "\nNumber of Seconds in " <<  Year << " is " << MyHeader::CalcNumberOfSeconds(Year) << endl;

    return (0);
}
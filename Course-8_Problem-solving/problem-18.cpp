#include "MyHeader.h"

int main(void)
{
    stDate Date1 = MyHeader::ReadFullDate();
    stDate Date2 = MyHeader::GetSystemDate();

    cout << "\nYou have lived for " << MyHeader::CalculateDifferenceInDays(Date1, Date2, true) << " Days." << endl;

    return (0);
}
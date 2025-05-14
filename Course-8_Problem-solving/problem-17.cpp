#include "MyHeader.h"

int main(void)
{
    stDate D1 = MyHeader::ReadFullDate();
    stDate D2 = MyHeader::ReadFullDate();

    cout << "\nDifference in days: " << MyHeader::CalculateDifferenceInDays(D1, D2) << " Day(s)." << endl;
    cout << "Difference in days (including the end day): "
        << MyHeader::CalculateDifferenceInDays(D1, D2, true) << " Day(s)." << endl; 
    return (0);
}
#include "MyHeader.h"

int main(void)
{
    cout << "\nEnter Period:" << endl;
    stPeriod Period = MyHeader::ReadPeriod();

    cout << "\nPeriod Length: " << MyHeader::PeriodLengthInDays(Period) << endl;
    cout << "\nPeriod Length (Including End date): " << MyHeader::PeriodLengthInDays(Period, true) << endl;

    return (0);
}
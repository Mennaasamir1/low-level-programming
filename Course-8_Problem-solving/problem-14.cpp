#include "MyHeader.h"

int main(void)
{
    stDate D1 = MyHeader::ReadFullDate();
    stDate D2 = MyHeader::ReadFullDate();

    if (MyHeader::IsDate1EqualToDate2(D1, D2))
    {
        cout << "\nYes, both dates are equal" << endl;
    }
    else
    {
        cout << "\nNo, They're not equal" << endl; 
    }

    return (0);
}
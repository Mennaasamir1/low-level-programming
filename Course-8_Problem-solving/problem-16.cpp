#include "MyHeader.h"

int main(void)
{
    stDate Date = MyHeader::ReadFullDate();

    Date = MyHeader::IncreaseDateByOne(Date);

    cout << "\nDate increased by one day: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    return (0);
}
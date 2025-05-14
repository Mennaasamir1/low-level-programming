#include "MyHeader.h"

int main(void)
{
    stDate Date = MyHeader::ReadFullDate();

    Date = MyHeader::IncreaseDateByOne(Date);

    cout << "\nDate After:\n\n";
    cout << "\n01-Adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::IncreaseDateByXDays(Date, 31);
    cout << "\n02-Adding 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::IncreaseDateByOneWeek(Date);
    cout << "\n03-Adding one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::IncreaseDateByXWeeks(Date, 10);
    cout << "\n04-Adding 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::IncreaseDateByOneMonth(Date);
    cout << "\n05-Adding one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::IncreaseDateByXMonths(Date, 2);
    cout << "\n06-Adding two months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::IncreaseDateByOneYear(Date);
    cout << "\n07-Adding One year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::IncreaseDateByXYears(Date, 3);
    cout << "\n08-Adding 3 years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::IncreaseDateByOneDecade(Date);
    cout << "\n09-Adding one decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::IncreaseDateByXDecades(Date, 4);
    cout << "\n10-Adding 4 decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::IncreaseDateByOneCentury(Date);
    cout << "\n11-Adding one century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::IncreaseDateByOneMillennium(Date);
    cout << "\n12-Adding one millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    return (0);
}
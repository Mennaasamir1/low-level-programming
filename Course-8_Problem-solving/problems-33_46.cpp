#include "MyHeader.h"

int main(void)
{
    stDate Date = MyHeader::ReadFullDate();

    Date = MyHeader::DecreaseDateByOneDay(Date);
    cout << "\n01-Decreasing one day: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::DecreaseDateByXDays(Date, 10);
    cout << "\n02-Decreasing 10 days: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::DecreaseDateByOneWeek(Date);
    cout << "\n03-Decreasing one week: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::DecreaseDateByXWeeks(Date, 10);
    cout << "\n04-Decreasing 10 weeks: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::DecreaseDateByOneMonth(Date);
    cout << "\n05-Decreasing one month: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::DecreaseDateByXMonths(Date, 5);
    cout << "\n06-Decreasing 5 months: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::DecreaseDateByOneYear(Date);
    cout << "\n07-Decreasing one year: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::DecreaseDateByXYears(Date, 10);
    cout << "\n08-Decreasing 10 years: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::DecreaseByOneDecade(Date);
    cout << "\n09-Decreasing one decade: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::DecreasingByXDecades(Date, 10);
    cout << "\n10-Decreasing 10 decades: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::DecreasingByOneCentury(Date);
    cout << "\n11-Decreasing one century: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = MyHeader::DecreasingOneMillennium(Date);
    cout << "\n12-Decreasing one millennium: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    return (0);
}
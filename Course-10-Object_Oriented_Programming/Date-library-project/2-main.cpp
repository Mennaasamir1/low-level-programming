#include "clsDate.h"
#include "clsPeriod.h"

int main(void)
{
    clsDate Date1("11/8/2025");
    clsDate Date2(23, 11, 2025);
    clsDate Date3(250, 2022);

    clsPeriod period1(clsDate("1/1/2025"), clsDate("20/24/2025"));

    period1.Print();

    Date1.IncreaseDateByOne();

    Date1.Print();

    Date2.DecreaseDateByOneDay();

    Date2.Print();
    Date3.Print();

    /**
    cout << "\nis date1 before date2? " << Date1.IsDate1BeforeDate2(Date2) << endl;

    
    Date1.PrintMonthCalender();

    clsDate::PrintYearCalender(2009);

    cout << "\nTotal days from the start of the year: "
        << Date1.TotalDaysFromBeginningOfYear() << " days." << endl;

    Date1.AddDaysToDate(5);

    Date1.Print();
    */
    

    return (0);
}
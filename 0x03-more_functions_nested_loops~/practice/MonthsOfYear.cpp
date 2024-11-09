#include "practice.h"

enum enMonthsOfYear
{
    Jan = 1, Feb = 2,
    Mar = 3, Apr = 4,
    May = 5, Jun = 6,
    Jul = 7, Aug = 8,
    Sep = 9, Oct = 10,
    Nov = 11, Dec = 12
};

int ValidateMonth(string Message, int From, int To)
{
    int Month = 0;

    do
    {
        cout << Message;
        cin >> Month;
    } while (Month < From || Month > To);

    return (Month);
}

enMonthsOfYear GetMonthOfYear(void)
{
    return ((enMonthsOfYear) ValidateMonth("\nEnter month number: ", 1, 12));
}

string PrintMonthName(enMonthsOfYear Month)
{
    cout << "\nIt's ";
    switch(Month)
    {
        case enMonthsOfYear::Jan:
            return ("January");
        case enMonthsOfYear::Feb:
            return ("February");
        case enMonthsOfYear::Mar:
            return ("March");
        case enMonthsOfYear::Apr:
            return ("April");
        case enMonthsOfYear::May:
            return ("May");
        case enMonthsOfYear::Jun:
            return ("June");
        case enMonthsOfYear::Jul:
            return ("July");
        case enMonthsOfYear::Aug:
            return ("August");
        case enMonthsOfYear::Sep:
            return ("September");
        case enMonthsOfYear::Oct:
            return ("October");
        case enMonthsOfYear::Nov:
            return ("November");
        case enMonthsOfYear::Dec:
            return ("December");
        default:
            return ("invalid month");
    }
}

int main(void)
{
    cout << PrintMonthName(GetMonthOfYear()) << endl;

    return (0);
}
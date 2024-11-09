#include "practice.h"

enum enDays 
{
    Sunday = 1, Monday = 2, 
    Tuesday = 3, Wednesday = 4,
    Thursday = 5, Friday = 6,
    Saturday = 7
};

int ReadNumberInRange(string Message, int From, int To)
{
    int N = 0;

    do
    {
        cout << Message << endl;
        cin >> N;
    } while (N < From || N > To);

    return (N);    
}

enDays ReadDays(void)
{
    return ((enDays) ReadNumberInRange("Enter the number of the day: ", 1, 7));
}

string GetDayOfTheWeek(enDays Day)
{
    cout << "It's ";
    switch (Day)
    {
    case enDays::Saturday:
        return ("Saturday");
    case enDays::Friday:
        return ("Friday");
    case enDays::Monday:
        return ("Monday");
    case enDays::Sunday:
        return ("Sunday");
    case enDays::Thursday:
        return ("Thursday");
    case enDays::Tuesday:
        return ("Tuesday");
    case enDays::Wednesday:
        return ("Wednesday");
    
    default:
        return ("Invalid day");
    }
}

int main(void)
{
    cout << GetDayOfTheWeek(ReadDays()) << endl;

    return (0);
}
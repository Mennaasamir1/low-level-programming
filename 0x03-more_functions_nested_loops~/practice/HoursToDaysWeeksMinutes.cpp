#include "practice.h"

float ReadPositiveNumber(string message)
{
    float N;

    do
    {
        cout << message << endl;
        cin >> N;

    } while (N < 0);
    
    return (N);
}

float HoursToDays(float NumberOfHours)
{
    return ((float)NumberOfHours / 24);
}

float HoursToWeeks(float NumberOfHours)
{
    return ((float) NumberOfHours / 24 / 7);
}

float DaysToWeeks(float NumberOfDays)
{
    return ((float) NumberOfDays / 7);
}
int main(void)
{
    float NumberOfHours = ReadPositiveNumber("Enter number of hours: ");
    float NumberOfDays = HoursToDays(NumberOfHours);
    float NumberOfWeeks = DaysToWeeks(NumberOfDays);

    cout << "Total hours = " << NumberOfHours << endl;
    cout << "Total Days = " << NumberOfDays << endl;
    cout << "Total Weeks = " << NumberOfWeeks << endl;

    return (0);
}
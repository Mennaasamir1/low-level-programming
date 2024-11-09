#include "practice.h"


struct stTaskDuration
{
    int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

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
stTaskDuration SecondsToTaskDuration(int TotalSeconds)
{
    stTaskDuration Task;
    const int SecondsPerDay = 24 * 60 * 60;
    const int SecondsPerHour = 24 * 60;
    const int SecondsPerMin = 60;
    int Remainder = 0;

    Task.NumberOfDays = floor(TotalSeconds / SecondsPerDay);
    Remainder = TotalSeconds % SecondsPerDay;
    Task.NumberOfHours = floor(Remainder / SecondsPerHour);
    Remainder = Remainder % SecondsPerHour;
    Task.NumberOfMinutes = floor(Remainder / SecondsPerMin);
    Remainder = Remainder % SecondsPerMin;
    Task.NumberOfSeconds = Remainder;

    return (Task);
}

void PrintTaskDuration(stTaskDuration Task)
{
    cout << "\n";
    cout << "Task duration = " << Task.NumberOfDays << ":"
        << Task.NumberOfHours << ":"
        << Task.NumberOfMinutes << ":"
        << Task.NumberOfSeconds << endl;
}

int main(void)
{
    int TotalSeconds = ReadPositiveNumber("Enter Total seconds: ");

    PrintTaskDuration(SecondsToTaskDuration(TotalSeconds));

    return (0);
}
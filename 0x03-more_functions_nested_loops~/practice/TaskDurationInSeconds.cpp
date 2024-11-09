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

stTaskDuration ReadInformation(void)
{
    stTaskDuration Task;

    Task.NumberOfDays = ReadPositiveNumber("Enter number of days: ");
    Task.NumberOfHours = ReadPositiveNumber("Enter number of hours: ");
    Task.NumberOfMinutes = ReadPositiveNumber("Enter number of minutes: ");
    Task.NumberOfSeconds = ReadPositiveNumber("Enter number of seconds: ");

    return (Task);
}


int TaskDurationInSeconds(stTaskDuration Task)
{
    int Duration = 0;

    cout << "Task duration in seconds = ";

    Duration = Task.NumberOfDays * 24 * 60 * 60;
    Duration += Task.NumberOfHours * 60 * 60;
    Duration += Task.NumberOfMinutes * 60;
    Duration += Task.NumberOfSeconds;

    return (Duration);
}

int main(void)
{
    cout << endl << TaskDurationInSeconds(ReadInformation()) << endl;
}
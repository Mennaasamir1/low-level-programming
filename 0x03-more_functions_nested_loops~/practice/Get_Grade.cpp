#include "practice.h"

int ReadMyGrade(int From, int To)
{
    int Grade;

    do
    {
        cout << "Enter your Grade: \n";
        cin >> Grade;
    } while (Grade < From || Grade > To);

    return (Grade);
}

char CheckMyGrade(int Grade)
{
    cout << "\nThe result is ";

    if (Grade >= 90)
        return ('A');

    else if (Grade >= 80)
        return ('B');

    else if (Grade >= 70)
        return ('C');

    else if (Grade >= 60)
        return ('D');

    else if (Grade >= 50)
        return ('E');
    
    else
        return ('F');
}

int main(void)
{
    cout << endl << CheckMyGrade(ReadMyGrade(0, 100)) << endl;

    return (0);
}
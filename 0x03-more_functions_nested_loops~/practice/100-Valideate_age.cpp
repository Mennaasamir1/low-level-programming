#include "practice.h"

int ReadAge(void)
{
    int age;

    cout << "How old are you?" << endl;
    cin >> age;

    return (age); 
}

bool ValidateNumberRange(int Number, int From, int To)
{
    return (Number >= From && Number <= To);
}

void PrintValidationResult(int Age)
{
    if (ValidateNumberRange(Age, 18, 45))
        cout << Age << " is a valid age\n";
    else
        cout << Age << " is invalid age\n";
}
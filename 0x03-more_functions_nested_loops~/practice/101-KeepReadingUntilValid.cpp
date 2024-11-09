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

int ReadUntilAgeBetween(int From, int To)
{
    int age;

    do
    {
        age = ReadAge();

    } while (!ValidateNumberRange(age, From, To));

    return (age);    
}

void PrintValidationResult(int Age)
{
    if (ValidateNumberRange(Age, 18, 45))
        cout << endl << Age << " is a valid age\n";
    else
        cout << endl << Age << " is invalid age\n";
}
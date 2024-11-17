#include "main.h"

int main(void)
{
    int Number = ReadAPositivenumber2("Enter a positive number: ");
    short DigitToCheck = ReadAPositivenumber2("Enter digit: ");

    cout << "Digit " << DigitToCheck << " frequency is " << DigitFrequency(Number, DigitToCheck) << " time(s)." << endl;

    return (0);
}
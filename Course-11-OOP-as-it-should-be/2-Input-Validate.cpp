#include "clsInputValidate.h"

int main(void)
{
    int x = 0;
    int y =  0;
    double A;
    double B;

  
    cout << "Enter a number: ";
    x = clsInputValidate::ReadIntNumber("invalid number");

    cout << x << endl;


    cout << "\nEnter a number between 1 and 5: ";
    y = clsInputValidate::ReadIntNumberBetween(1, 5, "invalid number\n");
    cout << y << endl;

    cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;
    cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(8, 12, 2025), clsDate(31, 12, 2025));
    cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(31, 12, 2025), clsDate(8, 12, 2025));

    cout << "\nEnter a double number: ";
    A = clsInputValidate::ReadDoubleNumber("invalid number. try again\n");
    cout << A << endl;

    cout << "Enter a double number between between 1 and 5: ";
    B = clsInputValidate::ReadDoubleNumberBetween(1, 5, "Number is not within range. try again\n");
    cout << B << endl;

    return (0);
}
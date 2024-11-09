#include "practice.h"

enum enCalculator {add = '+', sub = '-', mul = '*', divide = '/'};

float ReadtheNumber(string message)
{
    float number = 0;

    cout << message << endl;
    cin >> number;
    return (number);
}

enCalculator ReadOperationType(void)
{
    char OT;

    cout << "Enter operation type (+, -, *,  /)\n";
    cin >> OT;

    return ((enCalculator) OT);
}

float SimpleCalculator(float Num1, float Num2, enCalculator OT)
{
    switch (OT)
    {
    case enCalculator::add:
        return Num1 + Num2;
    case enCalculator::sub:
        return Num1 - Num2;
    case enCalculator::mul:
        return Num1 * Num2;
    case enCalculator::divide:
        return Num1 / Num2;
    default:
        return Num1 + Num2;
    }

}
int main(void)
{
    float Num1 = ReadtheNumber("Enter first number: ");
    float Num2 = ReadtheNumber("Enter second number: ");
    enCalculator OperationType = ReadOperationType();

    cout << endl << "Result = "<< SimpleCalculator(Num1, Num2, OperationType) << endl;

    return (0);
}
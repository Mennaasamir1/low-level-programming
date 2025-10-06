#include <iostream>
using namespace std;

template <class T>

class Calculator
{
    T Num1, Num2;

    public:
    Calculator(T N1, T N2)
    {
        Num1 = N1;
        Num2 = N2;
    }

    void PrintResults(void)
    {
        cout << "\nAdding result: " << Add() << endl; 
        cout << "\nSubtracting result: " << Sub() << endl; 
        cout << "\nMultiplication result: " << Multiply() << endl; 
        cout << "\nDividing result: " << Divide() << endl; 
    }

    T Add(void)
    {
        return (Num1 + Num2);
    }

    T Sub(void)
    {
        return (Num1 - Num2);
    }

    T Divide(void)
    {
        return (Num1 / Num2);
    }

    T Multiply(void)
    {
        return (Num1 * Num2);
    }
};

int main(void)
{
    Calculator <int> CalcInt(8, 4);
    Calculator <float> CalcFloat(6.2, 3.1);

    CalcInt.PrintResults();

    return (0);
}
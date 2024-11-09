#include "practice.h"

float ReadCircumference(void)
{
    float C;

    cout << "Enter circumference: ";
    cin >> C;

    return (C);
}

float CalcCircleAreaUsingCircumference(float C)
{
    const float PI = 3.141592653589793238;

    return (pow(C, 2) / (4 * PI));
}

void PrintCircleAreaUsingCircumference(float area)
{
    cout << "\nCircle area = " << area << endl;
}
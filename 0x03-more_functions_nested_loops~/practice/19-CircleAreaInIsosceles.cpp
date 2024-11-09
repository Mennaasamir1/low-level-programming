#include "practice.h"

void ReadSideAndBaseOfTriangle(float &side, float &base)
{
    cout << "Enter side of triangle: ";
    cin >> side;

    cout << "Enter base of triangle: ";
    cin >> base;
}

float CalculateCirCleAreaInIsoscelesTriangle(float s, float b)
{
    const float PI = 3.141592653589793238;
    float Area, p1, p2;

    p1 = PI * (pow(b, 2) / 4);
    p2 = ((2 * s - b) / (2 * s + b));

    Area = p1 * p2;

    return (Area);
}

void PrintCircleAreaInIsoscelesTriangle(float area)
{
    cout << "\nCircle area = " << area << endl;
}
#include "practice.h"

float ReadRadius(void)
{
    float radius;

    cout << "Enter radius: ";
    cin >> radius;

    return (radius);
}

float CalcCircleArea(float R)
{
    const float PI = 3.141592653589793238;

    return (pow(R, 2) * PI);
}

void PrintCircleArea(float area)
{
    cout << "\nCircle Area = " << area << endl;
}
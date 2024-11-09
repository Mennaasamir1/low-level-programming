#include "practice.h"

float ReadDiameter(void)
{
    float diameter;

    cout << "Enter diameter: ";
    cin >> diameter;

    return (diameter);
}

float CalcCircleAreaByDiameter(float d)
{
    const float PI = 3.141592653589793238;

    return ((PI * pow(d, 2)) / 4);
}

void PrintCicleAreaByDiameter(float area)
{
    cout << "\nCircle area = " << area << endl;
}
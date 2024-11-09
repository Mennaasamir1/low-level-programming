#include "practice.h"

float ReadSideOfSquare(void)
{
    float side;

    cout << "Enter side of square: ";
    cin >> side;

    return (side);
}

float CalcCircleAreaInSquare(float side)
{
    const float PI = 3.141592653589793238;

    return ((PI * pow(side, 2)) / 4);
}

void PrintCircleAreaInSquare(float area)
{
    cout << "\nCircle Area = " << area << endl;
}
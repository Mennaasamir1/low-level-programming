#include "practice.h"

void ReadDimensions(float &a, float &b)
{
    cout << "Enter height: ";
    cin >> a;

    cout << "Enter width: ";
    cin >> b;
}

float CalculateArea(float height, float width)
{
    return ((float) height * width);
}

void PrintResult(float Area)
{
    cout << "\nThe rectangle area = " << Area << endl;
}
#include "practice.h"

void ReadTriangleDimensions(float &base, float &height)
{
    cout << "Enter base of triangle: ";
    cin >> base;

    cout << "Enter height of triangle: ";
    cin >> height;
}

float CalcTriangleArea(float b, float h)
{
    return ((b / 2) * h);
}

void printAreaOfTriangle(float area)
{
    cout << "\nThe area of triangle = " << area << " cm" << endl;
}
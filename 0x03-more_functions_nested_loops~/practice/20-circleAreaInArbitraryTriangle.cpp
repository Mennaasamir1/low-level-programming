#include "practice.h"

void ReadDataOfTriangle(float &side1, float &side2, float &base)
{
    cout << "Enter side1: ";
    cin >> side1;

    cout << "Enter side2: ";
    cin >> side2;

    cout << "Enter base: ";
    cin >> base;
}

float CalcCircleAreaInArbitraryTriangle(float s1, float s2, float b)
{
    const float PI = 3.1415926535897932;
    float p = (s1 + s2 + b) / 2;
    float area1, Area;

    area1 = (s1 * s2 * b) / (4 * sqrt(p * (p - s1) * (p - s2) * (p - b)));

    Area = PI * pow(area1, 2);

    return (Area);
}

void PrintTheResult(float Area)
{
    cout << "\ncircle Area = " << Area << endl;
}
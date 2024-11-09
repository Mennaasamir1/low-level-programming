#include "practice.h"

void get_dimensions(float &s, float &d)
{
    cout << "Enter the diagonal of rectangle:" << endl;
    cin >> d;

    cout << "Enter side of rectangle:" << endl;
    cin >> s; 
}

float CalcAreaOfRectangle(float side, float d)
{
    float area = side * sqrt(pow(d, 2) - pow(side, 2));
    
    return (area);
}

void Print_Result(float area)
{
    cout << "The area of the rectangle = " << area << endl;
}
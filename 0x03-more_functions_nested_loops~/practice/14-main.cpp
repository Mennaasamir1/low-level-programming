#include "practice.h"

int main(void)
{
    float base, height;

    ReadTriangleDimensions(base, height);

    printAreaOfTriangle(CalcTriangleArea(base, height));
}
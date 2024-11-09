#include "practice.h"

int main(void)
{
    float side, base;

    ReadSideAndBaseOfTriangle(side, base);
    PrintCircleAreaInIsoscelesTriangle(CalculateCirCleAreaInIsoscelesTriangle(side, base));

    return (0);
}
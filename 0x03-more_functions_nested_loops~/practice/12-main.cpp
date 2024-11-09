#include "practice.h"

int main(void)
{
    float height, width;

    ReadDimensions(height, width);
    PrintResult(CalculateArea(height, width));

    return (0);
}
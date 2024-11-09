#include "practice.h"

int main(void)
{
    float s1, s2, base;

    ReadDataOfTriangle(s1, s2, base);
    PrintTheResult(CalcCircleAreaInArbitraryTriangle(s1, s2, base));
    return (0);
}